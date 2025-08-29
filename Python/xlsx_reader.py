import glob
import pandas as pd


if __name__ == '__main__':
    total_dict = {}
    root_path = input("输入文件路径（eg: D:/xlsxPath）：")
    name_str = input("输入名称列（eg: 商品名称）：")
    count_str = input("输入数量列（eg: 购买数量）：")
    file_paths = glob.glob(f"{root_path}/*.xlsx", recursive=True)
    for file_path in file_paths:
        excel_file = pd.ExcelFile(file_path)
        sheet_names = excel_file.sheet_names
        for sheet in sheet_names:
            df = excel_file.parse(sheet)
            columns = df.columns
            for row in range(len(df)):
                if name_str not in columns or count_str not in columns:
                    continue
                name = df.at[row, name_str]
                number = df.at[row, count_str]
                try:
                    num = int(number)
                except:
                    num = 0
                total_dict[name] = total_dict.get(name, 0) + num


    print("统计结果：")
    for k, v in total_dict.items():
        print("名称：" + str(k) + "\t" + "数量：" + str(v) + "\n")
    print("统计结果已保存到同目录下的output.txt文件中")
    with open(f"{root_path}/output.txt", "w", encoding="utf-8") as f:
        for k, v in total_dict.items():
            f.writelines("名称：" + str(k) + "\t" + "数量：" + str(v) + "\n")
    input("点击任意按钮关闭。。。")