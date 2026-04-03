import os
import sys

def main(input_file, output_file, target_length):
    f_in = open(input_file, 'r')
    
    bytes_to_write = []
    for l in f_in:
        l = l.strip().split(';')
        if len(l) <= 1:
            continue
        
        l = l[1].split()
        
        l_trim = ''
        l = l[1:]
        
        for b in l:
            bytes_to_write +=['{0:08b}'.format(int.from_bytes((bytes.fromhex(b))))]
    
    f_in.close()

    if len(bytes_to_write) > target_length:
        print("Binary is too big!")
        return
    
    #bytes_to_write += ['00'] * (target_length - len(bytes_to_write))
    print("Write %d bytes as strings to %s" % (len(bytes_to_write), output_file))

    f_out = open(output_file, 'w')
    f_out.write('\n'.join(bytes_to_write))
    f_out.close()

if __name__ == "__main__":
    print('start')
    # should be a path to a .txt as input and a .vivado (really also just text) as output
    # the input should be produced by z88dk-dis
    # the 'magic number' is the number of bytes that fit in the program ram.
    main(sys.argv[1], sys.argv[2], 60415 - 256)
    print("done")
