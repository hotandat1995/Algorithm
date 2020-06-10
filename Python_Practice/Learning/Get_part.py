import os

idf_path = os.environ['IDF_PATH'] + '/components'

folder_path = []
file_path = []
# r=root, d=directories, f = files
for r, d, f in os.walk(idf_path):
    for directories in d:
        split_path = directories.split('/')
        if (split_path[len(split_path)-1] == 'include'):
            folder_path.append(os.path.join(r, directories))

    for file in f:
        file_path.append(os.path.join(r,file))


# for f in folder_path:
#     print("\"" + f.replace(os.environ['IDF_PATH'], "${IDF_PATH}", 1) + "\",")

for f in file_path:
    if "hal.h" in f:
        print(f)
