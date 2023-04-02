import json

# 读取JSON文件
with open('E:\CodeAll\Python\example.json', 'r') as f:
    data = json.load(f)

# 输出JSON文件中的数据
print(data['name'])
print(data['age'])
print(data['city'])
print(data['hobbies'])
print(data['education']['degree'])
print(data['education']['major'])
