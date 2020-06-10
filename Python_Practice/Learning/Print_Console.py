import csv
from tabulate import tabulate

csv_file_path = "/home/htandat/Pit_tong/Memory_Tool/Output/memory_apss_analysis.csv"

with open(csv_file_path) as csv_file:
    module_detail = []
    total_size = []

    csv_reader = csv.reader(csv_file, delimiter=',')

    for line in csv_reader:
        if("Total:" in line):
            total_size = line
            break
        module_detail.append(line)

    module_detail.pop(1)
    module_detail.pop(1)

    total = ['', 'TXT', 'RO', 'DATA', 'BSS', 'TOTAL', 'FatalCount', 'F3Count']

    print("\nTotal size of sierra package:\n")
    print(tabulate([total,total_size],headers="firstrow",tablefmt="github"))

    print("\nDetail:\n")
    print(tabulate(module_detail,headers="firstrow",tablefmt="github"))
