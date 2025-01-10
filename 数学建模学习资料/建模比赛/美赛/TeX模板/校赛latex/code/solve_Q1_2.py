import numpy as np
import configs
import utils
from matplotlib import pyplot as plt



if __name__=="__main__":

    init_female_male=[0.1,0.2,0.4,0.6,0.8,0.9]

    for times in range(6):
        female_male=init_female_male[times]
        print(female_male)
        State_male=np.zeros(configs.Max_age)
        State_female=np.zeros(configs.Max_age)
        Y=np.zeros(configs.Max_impacts)
        P_male=np.zeros([configs.Max_age,configs.Max_age])
        P_female=np.zeros([configs.Max_age,configs.Max_age])
        Q_male=np.zeros([configs.Max_age,configs.Max_impacts])
        Q_female=np.zeros([configs.Max_age,configs.Max_impacts])
        
        State_male,State_female=utils.init_param(State_male,State_female,female_male=female_male)
        
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
            #print("echo:",year+1,"male:",male[-1],"female:",\
            #    female[-1],"total",total[-1])

        plt.subplot(2,3,times+1)
        plt.title('Female Proportion :'+str(init_female_male[times]))
        plt.xlabel('Time/year')
        plt.ylabel('Number')
        utils.draw_smooth_graph(total,name='total')
        plt.legend(loc='upper left')

    plt.show()