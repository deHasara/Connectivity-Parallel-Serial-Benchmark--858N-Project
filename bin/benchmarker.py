import os  
import sys   
import time
import subprocess

DEST_PATH = "../data/preped/temp" 

def snapTotemp(file_path): 
    node_mapping = {} 
    idx = 0;   
    

    source = open(file_path, "r")  

    for line in source: 
        edge = line.split()  
        if node_mapping.get(edge[0], None) == None: 
            node_mapping[edge[0]] = idx 
            idx += 1 
        if node_mapping.get(edge[1], None) == None: 
            node_mapping[edge[1]] = idx 
            idx += 1   
    
    source.close()

    if os.path.exists(DEST_PATH): 
        os.remove(DEST_PATH)
    dest = open(DEST_PATH, "w")  
    dest.write(str(idx)  + "\n")  

    source = open(file_path)
    for line in source: 
        edge = line.split() 
        dest.write(str(node_mapping[edge[0]]) + "," + str(node_mapping[edge[1]]) + "\n") 

    source.close() 
    dest.close()
     

################################# MAIN ##########################################################
if len(sys.argv) < 3: 
    print("USAGE\n python3 benchmarker.py [SNAP .edges file] [# of trails]\n EXAMPLE: python3 benchmarker.py ../data/SNAP/1.edges 10") 
    exit();  
  
snap_file = sys.argv[1]
snapTotemp(snap_file) 

trails = int(sys.argv[2]) 
total = 0.0  

if os.path.exists("./output"): 
    os.remove("./output")
output = open("./output", "w")  

print("****** Begining Benchmarking *******\n") 
for i in  range(trails): 
    start_time = time.time()
    subprocess.run("./main", stdout=output) 
    elasped_time = time.time() - start_time  
    total +=  elasped_time 
    print("Trail " + str(i + 1) + " Runtime: " + str(elasped_time) + " seconds\n")

output.close()    
print("Average Runtime: " + str(elasped_time/total) + " seconds")
