
import json

def print_out(ccid,imsi,opc,Ki):
	Out_String = ""
	Out_String += "    {\n"
	Out_String += "        // Sierra Wireless ICCID:<SIM CCID " + ccid + "> (JT)\n"
	Out_String += "        sim_algo: \"milenage\",\n"
	Out_String += "        imsi: \"" + str(imsi) + "\",\n"
	Out_String += "        opc: \"" + opc + "\",\n"
	Out_String += "        amf: 0x9001,\n"
	Out_String += "        sqn: \"000000000000\",\n"
	Out_String += "        K: \"" + Ki + "\",\n"
	Out_String += "        impi: \"" + str(imsi) + "@sierrawireless.com\",\n"
	Out_String += "        impu: [\":" + str(imsi) + "\", \"tel:+337000000000001\", \"tel:701\"],\n"
	Out_String += "    },\n"
	return Out_String

# Read Sim Data file
file = open('Test.json')

# Get data from file
all_data = json.load(file)

# Add the first line of pack
data_output = "\"ue_db:\" [\n"

# Phase data from list
data = all_data['Sim_Detail']
for Sim_data in data:
	for j in Sim_data['IMSI']:
		data_output += print_out(Sim_data['CCID'], j, Sim_data['OPc'], Sim_data['Ki'])

# Add the end line of pack
data_output += "\n]"

out_file = open(r"Output.txt","w")
out_file.write(data_output)