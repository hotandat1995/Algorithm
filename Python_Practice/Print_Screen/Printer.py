import Sample_Table


class Printer():

    def __init__(self, table):
        self.master_board = {}
        self.target_list = []
        self.name_list = []
        self.table_data = table
        self.table_size = self.get_table_detail()

        self.print_header()
        self.print_body()

    def get_table_detail(self):
        self.target_list = self.table_data.keys()
        self.get_table_list()
        self.init_master_board()
        self.update_masterboard()

        return self.update_table_size()

    def update_masterboard(self):
        for name in self.name_list:
            for target in self.target_list:
                temp = self.table_data.get(target)
                if(temp.get(name, None) != None):
                    self.master_board[name][target] = temp.get(name)
                else:
                    self.master_board[name][target] = {
                        'blksz': 'N/A', 'blocks': 'N/A', 'size': 'N/A'}

    def init_master_board(self):
        for name in self.name_list:
            self.master_board[name] = {}

    def get_table_list(self):
        raw_name_list = []
        # Scan all target to get names (have duplicate)
        for target in self.target_list:
            raw_name_list += self.table_data.get(target).keys()
        # Remove duplicate
        self.name_list = sorted(list(dict.fromkeys(raw_name_list)))

    def update_table_size(self):
        modun_template = {'first_line': 0, 'second_line':
                          {'blksz': len('blksz'), 'blocks': len('blocks'), 'size': len('size')}}

        table_size = {}

        for target in self.target_list:
            if target not in table_size:
                table_size[target] = modun_template

        for target in self.target_list:
            target_table = self.table_data[target].values()

            for line in target_table:
                if len(str(line['blksz'])) > table_size[target]['second_line']['blksz']:
                    table_size[target]['second_line']['blksz'] = len(str(line['blksz']))
                if len(str(line['blocks'])) > table_size[target]['second_line']['blocks']:
                    table_size[target]['second_line']['blocks'] = len(str(line['blocks']))
                if len(str(line['size'])) > table_size[target]['second_line']['size']:
                    table_size[target]['second_line']['size'] = len(str(line['size']))

            table_size[target]['first_line'] = sum(
                table_size[target]['second_line'].values()) + 2
        table_size['name_col_width'] = len(max(self.name_list, key=len))
        return table_size

    def print_header(self):

        first_floor = "|{:^{}}|".format(
            "NAME", self.table_size['name_col_width'])
        for target in self.target_list:
            first_floor += "{:^{}}|".format(target,
                                            self.table_size[target]['first_line'])
        print first_floor

        second_floor = "|{:^{}}|".format("", self.table_size['name_col_width'])
        thirth_floor = "|{:-<{}}|".format("",
                                          self.table_size['name_col_width'])
        for target in self.target_list:
            second_floor += "{:^{}}|".format("blksz",
                                             self.table_size[target]['second_line']['blksz'])
            thirth_floor += "{:-<{}}|".format(
                "", self.table_size[target]['second_line']['blksz'])
            second_floor += "{:^{}}|".format("blocks",
                                             self.table_size[target]['second_line']['blocks'])
            thirth_floor += "{:-<{}}|".format(
                "", self.table_size[target]['second_line']['blocks'])
            second_floor += "{:^{}}|".format("size",
                                             self.table_size[target]['second_line']['size'])
            thirth_floor += "{:-<{}}|".format("",
                                              self.table_size[target]['second_line']['size'])
        print second_floor + '\n' + thirth_floor

    def print_body(self):
        for name in self.name_list:
            # Format line:
            line_print = "|{:^{}}|".format(
                name, self.table_size['name_col_width'])
            for target in self.target_list:
                line_print += "{:^{}}|".format(
                    self.master_board[name][target]['blksz'],
                    self.table_size[target]['second_line']['blksz'])
                line_print += "{:^{}}|".format(
                    self.master_board[name][target]['blocks'],
                    self.table_size[target]['second_line']['blocks'])
                line_print += "{:^{}}|".format(
                    self.master_board[name][target]['size'],
                    self.table_size[target]['second_line']['size'])
            print line_print


if __name__ == "__main__":
    # FULL build:
    Sample_1 = {
        'modem': Sample_Table.MODEM_table,
        'apss': Sample_Table.APSS_table,
        'apss_tx': Sample_Table.APSS_TX_table,
        # 'boot': Sample_Table.BOOT_table
        'bootaaaa':{}
    }
    Test = Printer(Sample_1)
