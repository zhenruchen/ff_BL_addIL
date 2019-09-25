from bmtk.builder import NetworkBuilder
import numpy as np
from bmtk.builder.auxi.node_params import positions_cuboid, positions_list
import math
import random
np.random.seed(91)

# Initialize our network
netff = NetworkBuilder("ff_model")

# Create the possible x,y,z coordinates
xside_length = 600; yside_length = 600; height = 600; min_dist = 25;
ILxside_length = 800; ILyside_length =800;
IL_height13=1200
IL_height56=900
x_grid = np.arange(0,xside_length+min_dist,min_dist)
y_grid = np.arange(0,yside_length+min_dist,min_dist)

ILx_grid = np.arange(-200,ILxside_length+min_dist,min_dist)
ILy_grid = np.arange(-200,ILyside_length+min_dist,min_dist)
z_grid = np.arange(0,height+min_dist,min_dist)
IL13_z_grid = np.arange(600+30+232+236+180,600+30+232+236+180+101+min_dist,min_dist)
IL56_z_grid = np.arange(600+30+232,600+30+232+264+min_dist,min_dist)
xxBL, yyBL, zzBL = np.meshgrid(x_grid, y_grid, z_grid)
xxIL13, yyIL13, zzIL13 = np.meshgrid(x_grid, y_grid, IL13_z_grid)
xxIL56, yyIL56, zzIL56 = np.meshgrid(x_grid, y_grid, IL56_z_grid)
BL_pos_list = np.vstack([xxBL.ravel(), yyBL.ravel(), zzBL.ravel()]).T
IL13_pos_list = np.vstack([xxIL13.ravel(), yyIL13.ravel(), zzIL13.ravel()]).T
IL56_pos_list = np.vstack([xxIL56.ravel(), yyIL56.ravel(), zzIL56.ravel()]).T
# Number of cells in each population
numPN_A = 640
numPN_C = 260
numBask = 100
numIL13_Pyr=230
numIL13_Bask=40
numIL56_Pyr=350
numIL56_Bask=60
numBL=numPN_A+numPN_C+numBask
numIL13=numIL13_Pyr+numIL13_Bask
########################Select 10% of IL56
##empty
########################Select 25% of BL
templist=list(range(0, numPN_A+numPN_C-1))
list_0_25_BL_P = random.sample(templist, round(0.25*(numPN_A+numPN_C)))
########################Select 20% of IL5
templist=list(range(numBL+numIL13, numBL+numIL13+numIL56_Pyr-1))
list_0_20_IL5_P = random.sample(templist, round(0.20*numIL56_Pyr))
########################Select20% of IL2
templist=list(range(numBL, numBL+numIL13_Pyr-1))
list_0_20_IL2_P = random.sample(templist, round(0.20*numIL13_Pyr))
########################Select 4% of IL2
templist=list(range(numBL, numBL+numIL13_Pyr-1))
list_0_04_IL2_P = random.sample(templist, round(0.04*numIL13_Pyr))
########################Select 5.5% of IL5
templist=list(range(numBL+numIL13, numBL+numIL13+numIL56_Pyr-1))
list_0_055_IL5_P = random.sample(templist, round(0.055*numIL56_Pyr))
########################Select 10% of IL5
templist=list(range(numBL+numIL13, numBL+numIL13+numIL56_Pyr-1))
list_0_10_IL5_P = random.sample(templist, round(0.1*numIL56_Pyr))
########################Select 8% of BL
templist=list(range(0, numPN_A+numPN_C-1))
list_0_08_BL_P = random.sample(templist, round(0.08*(numPN_A+numPN_C)))
###################################################################################
####################################Pyr Type A#####################################

# Pick coordinates
inds = np.random.choice(np.arange(0,np.size(BL_pos_list,0)),numPN_A,replace=False)
pos = BL_pos_list[inds,:]

# Add a population of numPN_A nodes (all of which share model_type, dynamics_params, etc.)
#net.add_nodes(N=numPN_A, pop_name='PyrA',
#              positions=positions_list(positions=pos),
#              mem_potential='e',
#              model_type='biophysical',
#              model_template='ctdb:Biophys1.hoc',
#              model_processing='aibs_perisomatic',
#              dynamics_params='472363762_fit.json',
#              morphology='Scnn1a_473845048_m.swc')
netff.add_nodes(N=numPN_A, pop_name='Cell_A',
                positions=positions_list(positions=pos),
                potental='exc',
                model_type='biophysical',
                model_template='hoc:Cell_A',
                morphology=None
                )
##################################################################################
###################################Pyr Type C#####################################

# Get rid of coordinates already used
pos_list = np.delete(BL_pos_list,inds,0)

# Pick new coordinates
inds = np.random.choice(np.arange(0,np.size(BL_pos_list,0)),numPN_C,replace=False)
pos = BL_pos_list[inds,:]

# Add a population of numPN_C nodes (all of which share model_type, dynamics_params, etc.)
#net.add_nodes(N=numPN_C, pop_name='PyrC',
#              positions=positions_list(positions=pos),
#              mem_potential='e',
#              model_type='biophysical',
#              model_template='ctdb:Biophys1.hoc',
#              model_processing='aibs_perisomatic',
#              dynamics_params='472363762_fit.json',
#              morphology='Scnn1a_473845048_m.swc')
netff.add_nodes(N=numPN_C, pop_name='Cell_C',
                positions=positions_list(positions=pos),
                potental='exc',
                model_type='biophysical',
                model_template='hoc:Cell_C',
                morphology=None
                )
############## ###################################################################
###########################Fast - spiking PV ints################################

# Get rid of coordinates already used
BL_pos_list = np.delete(pos_list,inds,0)

# Pick new coordinates
inds = np.random.choice(np.arange(0,np.size(BL_pos_list,0)),numBask,replace=False)
pos = BL_pos_list[inds,:]

# Add a population of numBask nodes
#net.add_nodes(N=numBask, pop_name='Bask',
#              positions=positions_list(positions=pos),
#              mem_potential='e',
#              model_type='biophysical',
#              model_template='ctdb:Biophys1.hoc',
#              model_processing='aibs_perisomatic',
#              dynamics_params='472363762_fit.json',
#              morphology='Scnn1a_473845048_m.swc')
netff.add_nodes(N=numBask,pop_name='Cell_Bask',
                positions=positions_list(positions=pos),
                potental='inh',
                model_type='biophysical',
                model_template='hoc:Cell_PN',
                morphology=None
                )


###################################################################################
####################################IL13  Pyr #####################################

# Pick coordinates
inds = np.random.choice(np.arange(0,np.size(IL13_pos_list,0)),numIL13_Pyr,replace=False)
pos = IL13_pos_list[inds,:]

# Add a population of numPN_A nodes (all of which share model_type, dynamics_params, etc.)
#net.add_nodes(N=numPN_A, pop_name='PyrA',
#              positions=positions_list(positions=pos),
#              mem_potential='e',
#              model_type='biophysical',
#              model_template='ctdb:Biophys1.hoc',
#              model_processing='aibs_perisomatic',
#              dynamics_params='472363762_fit.json',
#              morphology='Scnn1a_473845048_m.swc')
netff.add_nodes(N=numIL13_Pyr, pop_name='IL13_Pyr',
                positions=positions_list(positions=pos),
                potental='exc',
                model_type='biophysical',
                model_template='hoc:Cell_A',
                morphology=None
                )

#################################################################################
###########################IL13 Interneuron################################

# Get rid of coordinates already used
IL13_pos_list = np.delete(IL13_pos_list,inds,0)

# Pick new coordinates
inds = np.random.choice(np.arange(0,np.size(IL13_pos_list,0)),numIL13_Bask,replace=False)
pos = IL13_pos_list[inds,:]

# Add a population of numBask nodes
#net.add_nodes(N=numIL13_Bask, pop_name='Bask',
#              positions=positions_list(positions=pos),
#              mem_potential='e',
#              model_type='biophysical',
#              model_template='ctdb:Biophys1.hoc',
#              model_processing='aibs_perisomatic',
#              dynamics_params='472363762_fit.json',
#              morphology='Scnn1a_473845048_m.swc')
netff.add_nodes(N=numIL13_Bask,pop_name='IL13_Bask',
                positions=positions_list(positions=pos),
                potental='inh',
                model_type='biophysical',
                model_template='hoc:Cell_PN',
                morphology=None
                )

###################################################################################
####################################IL56  Pyr #####################################

# Pick coordinates
inds = np.random.choice(np.arange(0,np.size(IL56_pos_list,0)),numIL56_Pyr,replace=False)
pos = IL56_pos_list[inds,:]

# Add a population of numPN_A nodes (all of which share model_type, dynamics_params, etc.)
#net.add_nodes(N=numPN_A, pop_name='PyrA',
#              positions=positions_list(positions=pos),
#              mem_potential='e',
#              model_type='biophysical',
#              model_template='ctdb:Biophys1.hoc',
#              model_processing='aibs_perisomatic',
#              dynamics_params='472363762_fit.json',
#              morphology='Scnn1a_473845048_m.swc')
netff.add_nodes(N=numIL56_Pyr, pop_name='IL56_Pyr',
                positions=positions_list(positions=pos),
                potental='exc',
                model_type='biophysical',
                model_template='hoc:Cell_A',
                morphology=None
                )

#################################################################################
###########################IL56 Interneuron################################

# Get rid of coordinates already used
IL13_pos_list = np.delete(IL56_pos_list,inds,0)

# Pick new coordinates
inds = np.random.choice(np.arange(0,np.size(IL56_pos_list,0)),numIL56_Bask,replace=False)
pos = IL56_pos_list[inds,:]

# Add a population of numBask nodes
#net.add_nodes(N=numIL56_Bask, pop_name='Bask',
#              positions=positions_list(positions=pos),
#              mem_potential='e',
#              model_type='biophysical',
#              model_template='ctdb:Biophys1.hoc',
#              model_processing='aibs_perisomatic',
#              dynamics_params='472363762_fit.json',
#              morphology='Scnn1a_473845048_m.swc')
netff.add_nodes(N=numIL56_Bask,pop_name='IL56_Bask',
                positions=positions_list(positions=pos),
                potental='inh',
                model_type='biophysical',
                model_template='hoc:Cell_PN',
                morphology=None
                )

##############################################################################
############################## CONNECT CELLS #################################

def dist_conn_perc(source, target, prob=0.1, min_dist=0.0, max_dist=300.0, min_syns=1, max_syns=2):
    #print("???")
    sid = source.node_id
    tid = target.node_id
    # No autapses
    if sid==tid:
        return None
    else:
        src_pos = source['positions']
        trg_pos = target['positions']
    dist =np.sqrt((src_pos[0]-trg_pos[0])**2+(src_pos[1]-trg_pos[1])**2+(src_pos[2]-trg_pos[2])**2)
        #print("src_pos: {} trg_pos: {} dist: {}".format(src_pos,trg_pos,dist))

    if dist <= max_dist and np.random.uniform() < prob:
        tmp_nsyn = np.random.randint(min_syns, max_syns)
        print("{}to{}done".format(sid,tid))
        #print("creating {} synapse(s) between cell {} and {}".format(tmp_nsyn,sid,tid))
    else:
        tmp_nsyn = 0

    return tmp_nsyn

def dist_conn_perc1(source, target,prob=0 ,min_dist=0, max_dist=600, min_syns=1, max_syns=1):

        x_ind,y_ind,z_ind = 0,1,2
        dx = target['positions'][x_ind] - source['positions'][x_ind]
        dy = target['positions'][y_ind] - source['positions'][y_ind]
        dz = target['positions'][z_ind] - source['positions'][z_ind]
        #distxyz = math.sqrt(dx**2 + dy**2)
        distxyz = math.sqrt(dx**2 + dy**2 + dz**2)
	#print("conn one")
        prob = 1

        if distxyz <= 50:
            prob = 0.03

        elif distxyz <= 100:
            prob = 0.02
        elif distxyz <= 200:
            prob = 0.01

        else:
            prob = 0.005

        if random.random() < prob:
            #Since there will be recurrect connections we need to keep track externally to BMTK
            #BMTK will call build_edges twice if we use net.edges() before net.build()
            #Resulting in double the edge count
            #syn_list.append({'source_gid':source['node_id'],'target_gid':target['node_id']})
            tmp_nsyn= 1 ## random.randint(min_syns,max_syns)
            print("{}to{}done".format(source.node_id,target.node_id))
        else:
            tmp_nsyn=0
        #print('PyrA, PyrC connection=',tmp_nsyn)
        return tmp_nsyn


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

    if dist <= max_dist and (Pid-1)*6 <= Iid and Iid < Pid*6: ## and np.random.uniform() < prob:
        tmp_nsyn = np.random.randint(min_syns, max_syns)
        print("{}to{}done".format(sid,tid))
        #print("creating {} synapse(s) between cell {} and {}".format(tmp_nsyn,sid,tid))
    else:
        tmp_nsyn = 0

    return tmp_nsyn

def IL2_i2p_conn(source, target, prob=0.1, min_dist=0.0, max_dist=300.0,
                 min_syns=1, max_syns=2, umBL=numBL, numIL13_Pyr = numIL13_Pyr):
    sid = source.node_id
    tid = target.node_id
    Pid=sid-numBL
    Iid=tid-numBL-numIL13_Pyr

    src_pos = source['positions']
    trg_pos = target['positions']
    dist =np.sqrt((src_pos[0]-trg_pos[0])**2+(src_pos[1]-trg_pos[1])**2+(src_pos[2]-trg_pos[2])**2)
        #print("src_pos: {} trg_pos: {} dist: {}".format(src_pos,trg_pos,dist))

    if dist <= max_dist and (Pid-1)*6<=Iid and Iid<Pid*6: ## and np.random.uniform() < prob:
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

    if dist <= max_dist and (Pid-1)*6<=Iid and Iid<Pid*6: ## and np.random.uniform() < prob:
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

    if dist <= max_dist and (Pid-1)*6<=Iid and Iid<Pid*6: ## and np.random.uniform() < prob:
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

    if dist <= max_dist and (Pid-1)*6<=Iid and Iid<Pid*6: ## and np.random.uniform() < prob:
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

    if dist <= max_dist and (Pid-1)*6<=Iid and Iid<Pid*6: ## and np.random.uniform() < prob:
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
    if sid in list_0_25_BL_P and tid in list_0_20_IL2_P:
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

    src_pos = source['positions']
    trg_pos = target['positions']
    dist =np.sqrt((src_pos[0]-trg_pos[0])**2+(src_pos[1]-trg_pos[1])**2+(src_pos[2]-trg_pos[2])**2)
        #print("src_pos: {} trg_pos: {} dist: {}".format(src_pos,trg_pos,dist))
    if sid in list_0_25_BL_P and tid in list_0_20_IL5_P:
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
        if sid in list_0_04_IL2_P and tid in list_0_08_BL_P:
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
        if sid in list_0_055_IL5_P and tid in list_0_08_BL_P:
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
        if sid in list_0_10_IL5_P:
            if dist <= max_dist: ## and np.random.uniform() < prob:
                tmp_nsyn = np.random.randint(min_syns, max_syns)
                print("{}to{}done".format(sid,tid))
            #print("creating {} synapse(s) between cell {} and {}".format(tmp_nsyn,sid,tid))
            else:
                tmp_nsyn = 0
        else: return 0
        return tmp_nsyn

# Create connections between Pyr --> Bask cells
netff.add_edges(source={'pop_name': ['Cell_A','Cell_C']}, target={'pop_name': 'Cell_Bask'},
                connection_rule=dist_conn_perc,
                connection_params={'prob':0.12,'min_dist':0.0,'max_dist':300.0,'min_syns':1,'max_syns':2},
                syn_weight=5.0e-03,
                dynamics_params='AMPA_ExcToInh.json',
                model_template='Exp2Syn',
                distance_range=[0.0, 300.0],
                target_sections=['somatic'],
                delay=2.0)

# Create connections between Bask --> Pyr cells
print("?????")
netff.add_edges(source={'pop_name': 'Cell_Bask'}, target={'pop_name': ['Cell_A','Cell_C']},
                connection_rule=dist_conn_perc,
                connection_params={'prob':0.34,'min_dist':0.0,'max_dist':300.0,'min_syns':1,'max_syns':2},
                syn_weight=5.0e-03,
                dynamics_params='GABA_InhToExc.json',
                model_template='Exp2Syn',
                distance_range=[0.0, 300.0],
                target_sections=['somatic'],
                delay=2.0)

# Create connections between Pyr --> Pyr cells
netff.add_edges(source={'pop_name': ['Cell_A','Cell_C']}, target={'pop_name': ['Cell_A','Cell_C']},
                connection_rule=dist_conn_perc1,
                connection_params={'prob':0.01,'min_dist':0.0,'max_dist':300.0,'min_syns':1,'max_syns':2},
                syn_weight=5.0e-03,
                dynamics_params='AMPA_ExcToExc.json',
                model_template='Exp2Syn',
                distance_range=[0.0, 300.0],
                target_sections=['somatic'],
                delay=2.0
                )
# Create connections between Bask --> Bask cells
netff.add_edges(source={'pop_name': 'Cell_Bask'}, target={'pop_name': 'Cell_Bask'},
                connection_rule=dist_conn_perc,
                connection_params={'prob':0.26,'min_dist':0.0,'max_dist':600,'min_syns':1,'max_syns':2},
                syn_weight=5.0e-03,
                dynamics_params='GABA_InhToInh.json',
                model_template='Exp2Syn',
                distance_range=[0.0, 600.0],
                target_sections=['somatic'],
                delay=2.0)
netff.build()
netff.save_nodes(output_dir='network')
netff.save_edges(output_dir='network')


#########################################################
#######################inside IL2

# Create connections between Pyr --> Bask cells
netff.add_edges(source={'pop_name': 'IL13_Pyr'}, target={'pop_name': 'IL13_Bask'},
                connection_rule=dist_conn_perc,
                connection_params={'prob':0.12,'min_dist':0.0,'max_dist':300.0,'min_syns':1,'max_syns':2},
                syn_weight=5.0e-03,
                dynamics_params='AMPA_ExcToInh.json',
                model_template='Exp2Syn',
                distance_range=[0.0, 300.0],
                target_sections=['somatic'],
                delay=2.0)

# Create connections between Bask --> Pyr cells
print("?????")
netff.add_edges(source={'pop_name': 'IL13_Bask'}, target={'pop_name': 'IL13_Pyr'},
                connection_rule=dist_conn_perc,
                connection_params={'prob':0.34,'min_dist':0.0,'max_dist':300.0,'min_syns':1,'max_syns':2},
                syn_weight=5.0e-03,
                dynamics_params='GABA_InhToExc.json',
                model_template='Exp2Syn',
                distance_range=[0.0, 300.0],
                target_sections=['somatic'],
                delay=2.0)

# Create connections between Pyr --> Pyr cells
netff.add_edges(source={'pop_name': 'IL13_Pyr'}, target={'pop_name': 'IL13_Pyr'},
                connection_rule=dist_conn_perc1,
                connection_params={'prob':0.012*72,'min_dist':0.0,'max_dist':300.0,'min_syns':1,'max_syns':2},
                syn_weight=5.0e-03,
                dynamics_params='AMPA_ExcToExc.json',
                model_template='Exp2Syn',
                distance_range=[0.0, 300.0],
                target_sections=['somatic'],
                delay=2.0
                )
# Create connections between Bask --> Bask cells
netff.add_edges(source={'pop_name': 'IL13_Bask'}, target={'pop_name': 'IL13_Bask'},
                connection_rule=dist_conn_perc,
                connection_params={'prob':0.26,'min_dist':0.0,'max_dist':600,'min_syns':1,'max_syns':2},
                syn_weight=5.0e-03,
                dynamics_params='GABA_InhToInh.json',
                model_template='Exp2Syn',
                distance_range=[0.0, 600.0],
                target_sections=['somatic'],
                delay=2.0)


#########################################################
#######################inside IL56

# Create connections between Pyr --> Bask cells
netff.add_edges(source={'pop_name': 'IL56_Pyr'}, target={'pop_name': 'IL56_Bask'},
                connection_rule=dist_conn_perc,
                connection_params={'prob':0.12,'min_dist':0.0,'max_dist':300.0,'min_syns':1,'max_syns':2},
                syn_weight=5.0e-03,
                dynamics_params='AMPA_ExcToInh.json',
                model_template='Exp2Syn',
                distance_range=[0.0, 300.0],
                target_sections=['somatic'],
                delay=2.0)

# Create connections between Bask --> Pyr cells
print("?????")
netff.add_edges(source={'pop_name': 'IL13_Bask'}, target={'pop_name': 'IL13_Pyr'},
                connection_rule=dist_conn_perc,
                connection_params={'prob':0.34,'min_dist':0.0,'max_dist':300.0,'min_syns':1,'max_syns':2},
                syn_weight=5.0e-03,
                dynamics_params='GABA_InhToExc.json',
                model_template='Exp2Syn',
                distance_range=[0.0, 300.0],
                target_sections=['somatic'],
                delay=2.0)

# Create connections between Pyr --> Pyr cells
netff.add_edges(source={'pop_name': 'IL56_Pyr'}, target={'pop_name': 'IL56_Pyr'},
                connection_rule=dist_conn_perc1,
                connection_params={'prob':0.027*72,'min_dist':0.0,'max_dist':300.0,'min_syns':1,'max_syns':2},
                syn_weight=5.0e-03,
                dynamics_params='AMPA_ExcToExc.json',
                model_template='Exp2Syn',
                distance_range=[0.0, 300.0],
                target_sections=['somatic'],
                delay=2.0
                )
# Create connections between Bask --> Bask cells
netff.add_edges(source={'pop_name': 'IL56_Bask'}, target={'pop_name': 'IL56_Bask'},
                connection_rule=dist_conn_perc,
                connection_params={'prob':0.26,'min_dist':0.0,'max_dist':600,'min_syns':1,'max_syns':2},
                syn_weight=5.0e-03,
                dynamics_params='GABA_InhToInh.json',
                model_template='Exp2Syn',
                distance_range=[0.0, 150.0],
                target_sections=['somatic'],
                delay=2.0)

###############################################
##############################From IL2 to IL5 and IL5 to IL2
####No IL2 to IL5
#add IL5 to IL 2, 10% of IL5_Pyr CELLS
netff.add_edges(source={'pop_name': 'IL56_Pyr'}, target={'pop_name': 'IL13_Pyr'},
                connection_rule=cross_layer_conn_IL5_IL2,
                connection_params={'prob':0.26,'min_dist':0.0,'max_dist':600,'min_syns':1,'max_syns':2},
                syn_weight=5.0e-03,
                dynamics_params='AMPA_ExcToExc.json',
                model_template='Exp2Syn',
                distance_range=[0.0, 800.0],
                target_sections=['somatic'],
                delay=2.0)
###############################################
########################From BL to IL2 and BL to IL5
netff.add_edges(source={'pop_name':['Cell_A','Cell_C']}, target={'pop_name': 'IL13_Pyr'},
                connection_rule=cross_layer_conn_BL_IL2,
                connection_params={'prob':0.26,'min_dist':0.0,'max_dist':600,'min_syns':1,'max_syns':2},
                syn_weight=5.0e-03,
                dynamics_params='AMPA_ExcToExc.json',
                model_template='Exp2Syn',
                distance_range=[0.0, 800.0],
                target_sections=['somatic'],
                delay=2.0)

netff.add_edges(source={'pop_name': ['Cell_A','Cell_C']}, target={'pop_name': 'IL56_Pyr'},
                connection_rule=cross_layer_conn_BL_IL5,
                connection_params={'prob':0.26,'min_dist':0.0,'max_dist':600,'min_syns':1,'max_syns':2},
                syn_weight=5.0e-03,
                dynamics_params='AMPA_ExcToExc.json',
                model_template='Exp2Syn',
                distance_range=[0.0, 800.0],
                target_sections=['somatic'],
                delay=2.0)

##################################################
###########################From IL2 to BL
netff.add_edges(source={'pop_name': 'IL13_Pyr'}, target={'pop_name': ['Cell_A','Cell_C']},
                connection_rule=cross_layer_conn_IL2_BL,
                connection_params={'prob':0.26,'min_dist':0.0,'max_dist':600,'min_syns':1,'max_syns':2},
                syn_weight=5.0e-03,
                dynamics_params='AMPA_ExcToExc.json',
                model_template='Exp2Syn',
                distance_range=[0.0, 800.0],
                target_sections=['somatic'],
                delay=2.0)
##################################################
###########################From IL5 to BL
netff.add_edges(source={'pop_name': 'IL56_Pyr'}, target={'pop_name': ['Cell_A','Cell_C']},
                connection_rule=cross_layer_conn_IL5_BL,
                connection_params={'prob':0.26,'min_dist':0.0,'max_dist':600,'min_syns':1,'max_syns':2},
                syn_weight=5.0e-03,
                dynamics_params='AMPA_ExcToExc.json',
                model_template='Exp2Syn',
                distance_range=[0.0, 800.0],
                target_sections=['somatic'],
                delay=2.0)




print("Internal nodes and edges built")

# Create connections between "thalamus" and Pyramidals
# First define the connection rule
def one_to_one(source, target):
    #print("one to one")
    sid = source.node_id
    tid = target.node_id

    if sid == tid:
        print("connecting cell {} to {}".format(sid,tid))
        tmp_nsyn = 1
    else:
        tmp_nsyn = 0
    return tmp_nsyn
################################################################################
############################# BACKGROUND INPUTS ################################

# External inputs
thalamus = NetworkBuilder('mthalamus')
thalamus.add_nodes(N=numPN_A+numPN_C+numBask,
                   pop_name='tON',
                   potential='exc',
                   model_type='virtual')
print(thalamus.nodes)
thalamus.add_edges(source=thalamus.nodes(), target=netff.nodes(pop_name='Cell_A'),
                   connection_rule=one_to_one,
                   syn_weight=0.1,
                   target_sections=['somatic'],
                   delay=2.0,
                   distance_range=[0.0, 300.0],
                   dynamics_params='AMPA_ExcToExc.json',
                   model_template='Exp2Syn')

thalamus.add_edges(source=thalamus.nodes(), target=netff.nodes(pop_name='Cell_C'),
                   connection_rule=one_to_one,
                   syn_weight=0.1,
                   target_sections=['somatic'],
                   delay=2.0,
                   distance_range=[0.0, 300.0],
                   dynamics_params='AMPA_ExcToExc.json',
                   model_template='Exp2Syn')

thalamus.add_edges(source=thalamus.nodes(), target=netff.nodes(pop_name='Cell_Bask'),
                   connection_rule=one_to_one,
                   syn_weight=0.1,
                   target_sections=['somatic'],
                   delay=2.0,
                   distance_range=[0.0, 600.0],
                   dynamics_params='AMPA_ExcToInh.json',
                   model_template='Exp2Syn')

# Build and save our network

thalamus.build()
thalamus.save_nodes(output_dir='network')
thalamus.save_edges(output_dir='network')

print("External nodes and edges built")

from bmtk.utils.sim_setup import build_env_bionet

build_env_bionet(base_dir='./',
		network_dir='./network',
		tstop=1000.0, dt = 0.1,
		spikes_inputs=[('mthalamus',   # Name of population which spikes will be generated for
                                'mthalamus_spikes.h5')],
		report_vars=['v', 'cai'],     # Record membrane potential and calcium (default soma)
		components_dir='biophys_components',
		compile_mechanisms=True)



from bmtk.utils.reports.spike_trains import PoissonSpikeGenerator

psg = PoissonSpikeGenerator(population='mthalamus')
psg.add(node_ids=range(numPN_A+numPN_C+numBask),  # Have nodes to match mthalamus
        firing_rate=15.0,    # 15 Hz, we can also pass in a nonhomoegenous function/array
        times=(0.0, 3.0))    # Firing starts at 0 s up to 3 s
psg.to_sonata('mthalamus_spikes.h5')
