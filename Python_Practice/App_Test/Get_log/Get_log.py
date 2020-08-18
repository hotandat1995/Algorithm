
input_file = open('FOTA.log', "r")
output_file = open('FOTA_kernel_log.log', "a")

for line in input_file:
    # if 'kernel' in line:
    #     output_file.write(line)
    if 'time_daemon_mdm' in line:
        output_file.write(line)
