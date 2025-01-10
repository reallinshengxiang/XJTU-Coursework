import numpy as np
import configs
import utils
from matplotlib import pyplot as plt

if __name__=="__main__":

    female_male=configs.initial_female_male
    State_male=np.zeros(configs.Max_age)
    State_female=np.zeros(configs.Max_age)
    Y=np.zeros(configs.Max_impacts)
    P_male=np.zeros([configs.Max_age,configs.Max_age])
    P_female=np.zeros([configs.Max_age,configs.Max_age])

    State_male,State_female=utils.init_param(State_male,State_female)
    
    male=[]
    female=[]
    total=[]
    
    for year in range(30):
        female_male=utils.cal_male_female(State_male,State_female)
        P_male,P_female=utils.update_param(female_male,P_male,P_female)
        State_male,State_female=utils.transition(State_male,State_female,\
            P_male,P_female)
        male.append(int(np.sum(State_male)))
        female.append(int(np.sum(State_female)))
        total.append(int(np.sum(State_male))+int(np.sum(State_female)))
        print(year+2015,male[-1],female[-1],total[-1])

    plt.subplot(1,2,1)
    plt.xlabel('Time/year')
    plt.ylabel('Number')
    utils.draw_smooth_graph(male,name='male')
    utils.draw_smooth_graph(female,name='female')
    plt.legend(loc='upper left')
    plt.subplot(1,2,2)
    plt.xlabel('Time/year')
    plt.ylabel('Number')
    utils.draw_smooth_graph(total,name='total')
    plt.legend(loc='upper left')
    plt.show()