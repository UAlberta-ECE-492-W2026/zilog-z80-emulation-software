import os
import sys

def main(input_file, output_file, target_length, start_padding_bytes = 0):
    f_in = open(input_file, 'r')
    
    bytes_to_write = []
    if start_padding_bytes:
        bytes_to_write += ['11000011', '00000000', '00000001']
        bytes_to_write += ['00000000'] * (start_padding_bytes - 3)
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
        print("Binary is too big!\n Max is %d and there are %d bytes to write." %(target_length, len(bytes_to_write)))
        return
    
    print("Parsed %d bytes." % (len(bytes_to_write) - start_padding_bytes))
    bytes_to_write += ['00000000'] * (target_length - len(bytes_to_write))
    print("Write %d bytes as strings to %s" % (len(bytes_to_write), output_file))

    f_out = open(output_file, 'w')
    f_out.write('\n'.join(bytes_to_write))
    f_out.write('\n')
    f_out.close()

if __name__ == "__main__":
    print('start')
    # should be a path to a .txt as input and a .vivado (really also just text) as output
    # the input should be produced by z88dk-dis
    # the 'magic number' is the number of bytes that fit in the program ram.
    if len(sys.argv) == 4:
        padding_bytes = sys.argv[3]
    else:
        padding_bytes = '0'
    
    #main(sys.argv[1], sys.argv[2], 13000, int('ff', 16))
    main(sys.argv[1], sys.argv[2], 60417, int(padding_bytes, 16))
    #main(sys.argv[1], sys.argv[2], 16384)
    print("done")
