
global numPN_A = 640
global numPN_C = 260
global numBask = 100
global numIL13_Pyr=230
global numIL13_Bask=40
global numIL56_Pyr=350
global numIL56_Bask=60
global numBL=numPN_A+numPN_C+numBask
global numIL13=numIL13_Pyr+numIL13_Bask
##############################################################################
############################## IL2 connection rules #################################

def IL2_p2i_conn(source, target, prob=0.1, min_dist=0.0, max_dist=300.0,
                min_syns=1, max_syns=2, numBL=numBL, numIL13_Pyr=numIL13_Pyr):
    sid = source.node_id
    tid = target.node_id
    Pid=sid-numBL
    Iid=tid-numBL-numIL13_Pyr

        src_pos = source['positions']
        trg_pos = target['positions']
    dist =np.sqrt((src_pos[0]-trg_pos[0])**2+(src_pos[1]-trg_pos[1])**2+(src_pos[2]-trg_pos[2])**2)
        #print("src_pos: {} trg_pos: {} dist: {}".format(src_pos,trg_pos,dist))

    if dist <= max_dist and (Pid-1)*6=<Iid and Iid<Pid*6: ## and np.random.uniform() < prob:
        tmp_nsyn = np.random.randint(min_syns, max_syns)
        print("{}to{}done".format(sid,tid))
        #print("creating {} synapse(s) between cell {} and {}".format(tmp_nsyn,sid,tid))
    else:
        tmp_nsyn = 0

    return tmp_nsyn

def IL2_i2p_conn(source, target, prob=0.1, min_dist=0.0, max_dist=300.0,
                min_syns=1, max_syns=2,numBL=numBL, numIL13_Pyr=numIL13_Pyr)):
    sid = source.node_id
    tid = target.node_id
    Pid=sid-numBL
    Iid=tid-numBL-numIL13_Pyr

        src_pos = source['positions']
        trg_pos = target['positions']
    dist =np.sqrt((src_pos[0]-trg_pos[0])**2+(src_pos[1]-trg_pos[1])**2+(src_pos[2]-trg_pos[2])**2)
        #print("src_pos: {} trg_pos: {} dist: {}".format(src_pos,trg_pos,dist))

    if dist <= max_dist and (Pid-1)*6=<Iid and Iid<Pid*6: ## and np.random.uniform() < prob:
        tmp_nsyn = np.random.randint(min_syns, max_syns)
        print("{}to{}done".format(sid,tid))
        #print("creating {} synapse(s) between cell {} and {}".format(tmp_nsyn,sid,tid))
    else:
        tmp_nsyn = 0

    return tmp_nsyn

def IL2_i2i_conn(source, target, prob=0.1, min_dist=0.0, max_dist=150.0, min_syns=1, max_syns=2):
    sid = source.node_id
    tid = target.node_id
    #Pid=sid-numBL
    #Iid=tid-numBL-numIL13_Pyr
    if sid==tid:
        return None
    else:
        src_pos = source['positions']
        trg_pos = target['positions']
    dist =np.sqrt((src_pos[0]-trg_pos[0])**2+(src_pos[1]-trg_pos[1])**2+(src_pos[2]-trg_pos[2])**2)
        #print("src_pos: {} trg_pos: {} dist: {}".format(src_pos,trg_pos,dist))

    if dist <= max_dist and (Pid-1)*6=<Iid and Iid<Pid*6: ## and np.random.uniform() < prob:
        tmp_nsyn = np.random.randint(min_syns, max_syns)
        print("{}to{}done".format(sid,tid))
        #print("creating {} synapse(s) between cell {} and {}".format(tmp_nsyn,sid,tid))
    else:
        tmp_nsyn = 0

    return tmp_nsyn

##############################################################################
############################## IL5 connection rules #################################

def IL2_p2i_conn(source, target, prob=0.1, min_dist=0.0,max_dist=300.0, min_syns=1,
		         max_syns=2, numBL=numBL, numIL13=numIL13, numIL56_Pyr=numIL56_Pyr):
    sid = source.node_id
    tid = target.node_id
    Pid=sid-numBL-numIL13
    Iid=tid-numBL-numIL13-numIL56_Pyr

        src_pos = source['positions']
        trg_pos = target['positions']
    dist =np.sqrt((src_pos[0]-trg_pos[0])**2+(src_pos[1]-trg_pos[1])**2+(src_pos[2]-trg_pos[2])**2)
        #print("src_pos: {} trg_pos: {} dist: {}".format(src_pos,trg_pos,dist))

    if dist <= max_dist and (Pid-1)*6=<Iid and Iid<Pid*6: ## and np.random.uniform() < prob:
        tmp_nsyn = np.random.randint(min_syns, max_syns)
        print("{}to{}done".format(sid,tid))
        #print("creating {} synapse(s) between cell {} and {}".format(tmp_nsyn,sid,tid))
    else:
        tmp_nsyn = 0

    return tmp_nsyn

def IL2_i2p_conn(source, target, prob=0.1, min_dist=0.0, max_dist=300.0, min_syns=1,
                max_syns=2, numBL=numBL, numIL13=numIL13, numIL56_Pyr=numIL56_Pyr):
    sid = source.node_id
    tid = target.node_id
    Pid=sid-numBL-numIL13
    Iid=tid-numBL-numIL13-numIL56_Pyr

        src_pos = source['positions']
        trg_pos = target['positions']
    dist =np.sqrt((src_pos[0]-trg_pos[0])**2+(src_pos[1]-trg_pos[1])**2+(src_pos[2]-trg_pos[2])**2)
        #print("src_pos: {} trg_pos: {} dist: {}".format(src_pos,trg_pos,dist))

    if dist <= max_dist and (Pid-1)*6=<Iid and Iid<Pid*6: ## and np.random.uniform() < prob:
        tmp_nsyn = np.random.randint(min_syns, max_syns)
        print("{}to{}done".format(sid,tid))
        #print("creating {} synapse(s) between cell {} and {}".format(tmp_nsyn,sid,tid))
    else:
        tmp_nsyn = 0

    return tmp_nsyn

def IL2_i2i_conn(source, target, prob=0.1, min_dist=0.0, max_dist=150.0, min_syns=1, max_syns=2):
    sid = source.node_id
    tid = target.node_id
    #Pid=sid-numBL
    #Iid=tid-numBL-numIL13_Pyr
    if sid==tid:
        return None
    else:
        src_pos = source['positions']
        trg_pos = target['positions']
    dist =np.sqrt((src_pos[0]-trg_pos[0])**2+(src_pos[1]-trg_pos[1])**2+(src_pos[2]-trg_pos[2])**2)
        #print("src_pos: {} trg_pos: {} dist: {}".format(src_pos,trg_pos,dist))

    if dist <= max_dist and (Pid-1)*6=<Iid and Iid<Pid*6: ## and np.random.uniform() < prob:
        tmp_nsyn = np.random.randint(min_syns, max_syns)
        print("{}to{}done".format(sid,tid))
        #print("creating {} synapse(s) between cell {} and {}".format(tmp_nsyn,sid,tid))
    else:
        tmp_nsyn = 0

    return tmp_nsyn

##############################################################################
############################## Cross layer connection rules BL_IL2#################################
def cross_layer_conn_BL_IL2(source, target, prob=0.1, min_dist=0.0, max_dist=150.0, min_syns=1, max_syns=2):
    sid = source.node_id
    tid = target.node_id
    #Pid=sid-numBL
    #Iid=tid-numBL-numIL13_Pyr
        src_pos = source['positions']
        trg_pos = target['positions']
    dist =np.sqrt((src_pos[0]-trg_pos[0])**2+(src_pos[1]-trg_pos[1])**2+(src_pos[2]-trg_pos[2])**2)
        #print("src_pos: {} trg_pos: {} dist: {}".format(src_pos,trg_pos,dist))
    if sid in 0_25_BL_P and tid in 0_20_IL2_P:
        if dist <= max_dist: ## and np.random.uniform() < prob:
            tmp_nsyn = np.random.randint(min_syns, max_syns)
            print("{}to{}done".format(sid,tid))
        #print("creating {} synapse(s) between cell {} and {}".format(tmp_nsyn,sid,tid))
        else:
            tmp_nsyn = 0
    else: return 0
    return tmp_nsyn
############################################

##############################################################################
############################## Cross layer connection rules BL_IL5#################################
def cross_layer_conn_BL_IL5(source, target, prob=0.1, min_dist=0.0, max_dist=150.0, min_syns=1, max_syns=2):
    sid = source.node_id
    tid = target.node_id
    #Pid=sid-numBL
    #Iid=tid-numBL-numIL13_Pyr
        src_pos = source['positions']
        trg_pos = target['positions']
    dist =np.sqrt((src_pos[0]-trg_pos[0])**2+(src_pos[1]-trg_pos[1])**2+(src_pos[2]-trg_pos[2])**2)
        #print("src_pos: {} trg_pos: {} dist: {}".format(src_pos,trg_pos,dist))
    if sid in 0_25_BL_P and tid in 0_20_IL5_P:
        if dist <= max_dist: ## and np.random.uniform() < prob:
            tmp_nsyn = np.random.randint(min_syns, max_syns)
            print("{}to{}done".format(sid,tid))
        #print("creating {} synapse(s) between cell {} and {}".format(tmp_nsyn,sid,tid))
        else:
            tmp_nsyn = 0
    else: return 0
    return tmp_nsyn

##############################################################################
############################## Cross layer connection rules IL2_BL################################
def cross_layer_conn_IL2_BL(source, target, prob=0.1, min_dist=0.0, max_dist=150.0, min_syns=1, max_syns=2):
        sid = source.node_id
        tid = target.node_id
        #Pid=sid-numBL
        #Iid=tid-numBL-numIL13_Pyr
            src_pos = source['positions']
            trg_pos = target['positions']
        dist =np.sqrt((src_pos[0]-trg_pos[0])**2+(src_pos[1]-trg_pos[1])**2+(src_pos[2]-trg_pos[2])**2)
            #print("src_pos: {} trg_pos: {} dist: {}".format(src_pos,trg_pos,dist))
        if sid in 0_04_IL2_P and tid in 0_08_BL_P:
            if dist <= max_dist: ## and np.random.uniform() < prob:
                tmp_nsyn = np.random.randint(min_syns, max_syns)
                print("{}to{}done".format(sid,tid))
            #print("creating {} synapse(s) between cell {} and {}".format(tmp_nsyn,sid,tid))
            else:
                tmp_nsyn = 0
        else: return 0
        return tmp_nsyn

##############################################################################
############################## Cross layer connection rules IL5_BL################################
def cross_layer_conn_IL5_BL(source, target, prob=0.1, min_dist=0.0, max_dist=150.0, min_syns=1, max_syns=2):
        sid = source.node_id
        tid = target.node_id
        #Pid=sid-numBL
        #Iid=tid-numBL-numIL13_Pyr
            src_pos = source['positions']
            trg_pos = target['positions']
        dist =np.sqrt((src_pos[0]-trg_pos[0])**2+(src_pos[1]-trg_pos[1])**2+(src_pos[2]-trg_pos[2])**2)
            #print("src_pos: {} trg_pos: {} dist: {}".format(src_pos,trg_pos,dist))
        if sid in 0_055_IL5_P and tid in 0_08_BL_P:
            if dist <= max_dist: ## and np.random.uniform() < prob:
                tmp_nsyn = np.random.randint(min_syns, max_syns)
                print("{}to{}done".format(sid,tid))
            #print("creating {} synapse(s) between cell {} and {}".format(tmp_nsyn,sid,tid))
            else:
                tmp_nsyn = 0
        else: return 0
        return tmp_nsyn

##############################################################################
############################## Cross layer connection rules IL5_IL2################################
def cross_layer_conn_IL5_IL2(source, target, prob=0.1, min_dist=0.0, max_dist=150.0, min_syns=1, max_syns=2):
        sid = source.node_id
        tid = target.node_id
        #Pid=sid-numBL
        #Iid=tid-numBL-numIL13_Pyr
            src_pos = source['positions']
            trg_pos = target['positions']
        dist =np.sqrt((src_pos[0]-trg_pos[0])**2+(src_pos[1]-trg_pos[1])**2+(src_pos[2]-trg_pos[2])**2)
            #print("src_pos: {} trg_pos: {} dist: {}".format(src_pos,trg_pos,dist))
        if sid in 0_10_IL5_P:
            if dist <= max_dist: ## and np.random.uniform() < prob:
                tmp_nsyn = np.random.randint(min_syns, max_syns)
                print("{}to{}done".format(sid,tid))
            #print("creating {} synapse(s) between cell {} and {}".format(tmp_nsyn,sid,tid))
            else:
                tmp_nsyn = 0
        else: return 0
        return tmp_nsyn
