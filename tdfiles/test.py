import os
import re
import glob
from difflib import SequenceMatcher

class DiagnosticParser:
    def __init__(self):
        self.diagnostics = {}  # 存储诊断ID和对应的错误信息模板
        self.file_mapping = {}  # 存储诊断ID和对应的文件名

    def parse_td_files(self, directory):
        """解析指定目录下的所有.td文件"""
        td_files = glob.glob(os.path.join(directory, "*.td"))
        for file_path in td_files:
            self.parse_file(file_path)
        print(f"已解析 {len(self.diagnostics)} 条诊断信息")

    def parse_file(self, file_path):
        """解析单个.td文件"""
        file_name = os.path.basename(file_path)
        with open(file_path, 'r', encoding='utf-8') as f:
            content = f.read()
        
        # 查找所有的诊断定义
        pattern = r'def\s+(err_\w+)\s*:\s*Error<\s*"([^"]+)"'
        matches = re.finditer(pattern, content)
        
        for match in matches:
            diag_id = match.group(1)
            message_template = match.group(2)
            
            # 清理模板中的特殊格式
            cleaned_template = self._clean_template(message_template)
            
            self.diagnostics[diag_id] = cleaned_template
            self.file_mapping[diag_id] = file_name

    def _clean_template(self, template):
        """清理诊断模板中的格式说明符"""
        # 替换 %0, %1 等占位符
        template = re.sub(r'%\d+', 'XXX', template)
        
        # 替换 %select{a|b|c}0 格式
        template = re.sub(r'%select{[^}]+}\d+', 'XXX', template)
        
        # 替换 %plural{a|b}0 格式
        template = re.sub(r'%plural{[^}]+}\d+', 'XXX', template)
        
        # 替换 %diff{a|b}0,1 格式
        template = re.sub(r'%diff{[^}]+}\d+,\d+', 'XXX', template)
        
        # 替换 %s0 格式
        template = re.sub(r'%s\d+', 's', template)
        
        # 替换 %human0 格式
        template = re.sub(r'%human\d+', 'XXX', template)
        
        # 替换 %ordinal0 格式
        template = re.sub(r'%ordinal\d+', 'XXX', template)
        
        return template

    def search_diagnostic(self, query, threshold=0.6):
        """搜索与查询字符串匹配的诊断信息"""
        results = []
        
        for diag_id, template in self.diagnostics.items():
            similarity = SequenceMatcher(None, query.lower(), template.lower()).ratio()
            if similarity > threshold:
                results.append((diag_id, template, similarity, self.file_mapping.get(diag_id, "未知文件")))
        
        # 按相似度排序
        results.sort(key=lambda x: x[2], reverse=True)
        return results

def main():
    parser = DiagnosticParser()
    
    # 假设.td文件在当前目录或指定目录
    td_directory = "."  # 可以修改为实际的目录路径
    parser.parse_td_files(td_directory)
    
    print("Clang 诊断信息查询工具")
    print("输入 'q' 退出")
    
    while True:
        query = input("\n请输入错误信息: ")
        if query.lower() == 'q':
            break
        
        results = parser.search_diagnostic(query)
        
        if not results:
            print("未找到匹配的诊断信息。请尝试使用不同的关键词。")
        else:
            print(f"\n找到 {len(results)} 个可能的匹配:")
            for i, (diag_id, template, similarity, file_name) in enumerate(results[:10], 1):
                print(f"{i}. {diag_id} (相似度: {similarity:.2f}) - 在 {file_name}")
                print(f"   模板: \"{template}\"")

if __name__ == "__main__":
    main()
