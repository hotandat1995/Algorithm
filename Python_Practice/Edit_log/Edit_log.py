#!/usr/bin/python
import csv
import sys
import getopt


def main(argv):
    input_file = ''
    output_file = ''
    try:
        opts, args = getopt.getopt(argv, "hi:o:", ["ifile=", "ofile="])
    except getopt.GetoptError:
        print 'Edit_log.py -i <input_file> -o <output_file>'
        sys.exit(2)
    for opt, arg in opts:
        if opt == '-h':
            print 'Edit_log.py -i <input_file> -o <output_file>'
            sys.exit()
        elif opt in ("-i", "--ifile"):
            input_file = arg
        elif opt in ("-o", "--ofile"):
            output_file = arg
        print 'Input file is: ', input_file
        print 'Output file is: ', output_file

    generate_log(input_file, output_file)


def generate_log(input, output):
    file_data = open(input, "r")
    header = ['Date', 'Time', 'Board', 'Scope', 'Legato', 'Debug level',
              'Process name', 'Process ID', 'Process Thread', 'Process Symbol',
              'Exec File Name', 'Func name', 'Thread ID', 'Message']

    with open(output, 'wb') as output_file:
        wr = csv.writer(output_file, dialect='excel')
        wr.writerow(header)

        for line in file_data:
            parts = line.split('|')

            if not ('root@' in parts[0]) and len(parts) == 4:
                # part 1: System detail
                system_detail = parts[0].split()

                date = '/'.join(system_detail[0:2])
                time, board, scope, legato, debug_level = system_detail[2:]
                # print(date + "   " + time + "  " + board + "  " + scope + "  " + legato + "  " + debug_level)

                # part 2: process detail
                process_name, process_id, process_thread, process_symbol = parts[1].replace(
                    '[', ' ').replace(']', ' ').replace('/', '').split()
                # print(process_name + process_id + process_thread + process_symbol)

                # part 3: executed file detail
                file_name, func_name, thread_id = parts[2].split()
                # print(file_name + "  " + func_name + "  " + thread_id)

                # part 4: Message log
                message_log = parts[3].replace('\n', '')
                # print (message_log)

                line_done = [date, time, board, scope, legato, debug_level, process_name, process_id,
                             process_thread, process_symbol, file_name, func_name, thread_id, message_log]
                wr.writerow(line_done)


if __name__ == "__main__":
    main(sys.argv[1:])
