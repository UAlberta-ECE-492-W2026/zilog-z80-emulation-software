import os
import sys

def main(input_file, output_file):
    f_in = open(input_file, 'r')
    f_out = open(output_file, 'w')
    for l in f_in:
        l = l.strip().split(';')
        if len(l) <= 1:
            continue
        
        l = l[1].split()
        
        l_trim = ''
        l = l[1:]
        
        for b in l:
            f_out.write(b + '\n')
    
    f_in.close()
    f_out.close()

if __name__ == "__main__":
    print('start')
    # should be a path to a .txt as input and a .vivado (really also just text) as output
    # the input should be produced by z88dk-dis
    main(sys.argv[1], sys.argv[2])
    print("done")
