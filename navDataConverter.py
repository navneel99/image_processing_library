f = open("data.txt",'r')
g = open ("dataOut.txt",'w')
l = f.readlines()
final_list =[]
for i in l: #each row
    line =''
    for j in i: #each character in line
        if j not in ['[',']','\n']:
            line+=j
    splitter = line.split()
    for k in splitter:
        final_list.append((k+'\n'))
#for t in final_list:
g.writelines(final_list)

f.close()
g.close()
