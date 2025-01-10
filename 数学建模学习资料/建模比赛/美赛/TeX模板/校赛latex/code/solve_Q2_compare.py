import numpy as np
import configs
import utils
from matplotlib import pyplot as plt



if __name__=="__main__":

    water_pollution_survive=[0.75,0.8,0.85,0.9,0.95,1]
    noise_survive=[0.75,0.8,0.85,0.9,0.95,1]

    for times in range(6):
        female_male=configs.initial_female_male
        State_male=np.zeros(configs.Max_age)
        State_female=np.zeros(configs.Max_age)
        Y=np.zeros(configs.Max_impacts)
        P_male=np.zeros([configs.Max_age,configs.Max_age])
        P_female=np.zeros([configs.Max_age,configs.Max_age])
        Q_male=np.zeros([configs.Max_age,configs.Max_impacts])
        Q_female=np.zeros([configs.Max_age,configs.Max_impacts])
        
        State_male,State_female=utils.init_param(State_male,State_female,\
            number=configs.initial_number_Yangtze_River,\
                female_male=configs.female_male_birth_Yangtze_River)
        
        male=[]
        female=[]
        total=[]
        
        for year in range(10):
            female_male=utils.cal_male_female(State_male,State_female)
            P_male,P_female=utils.update_param(female_male,P_male,P_female,survive_index=1,\
                pollution_impact=water_pollution_survive[times],\
                    noise_impact=configs.water_noise_survive_rate,\
                        artificial_impact=configs.artificial_survive_rate)
            State_male,State_female=utils.transition(State_male,State_female,\
                P_male,P_female,female_birth=configs.female_male_birth_Yangtze_River)
            male.append(int(np.sum(State_male)))
            female.append(int(np.sum(State_female)))
            total.append(int(np.sum(State_male))+int(np.sum(State_female)))
            print("echo:",year+1,"male:",male[-1],"female:",\
                female[-1],"total",total[-1])
        
        #plt.subplot(2,3,times+1)
        plt.xlabel('Time/year')
        plt.ylabel('Number')
        utils.draw_smooth_graph(total,name='Water pollution impact: '+str(water_pollution_survive[times]),start_year=2021)
        plt.legend(loc='upper right')
    plt.show()

    for times in range(6):
        female_male=configs.initial_female_male
        State_male=np.zeros(configs.Max_age)
        State_female=np.zeros(configs.Max_age)
        Y=np.zeros(configs.Max_impacts)
        P_male=np.zeros([configs.Max_age,configs.Max_age])
        P_female=np.zeros([configs.Max_age,configs.Max_age])
        Q_male=np.zeros([configs.Max_age,configs.Max_impacts])
        Q_female=np.zeros([configs.Max_age,configs.Max_impacts])
        
        State_male,State_female=utils.init_param(State_male,State_female,\
            number=configs.initial_number_Yangtze_River,\
                female_male=configs.female_male_birth_Yangtze_River)
        
        male=[]
        female=[]
        total=[]
        
        for year in range(10):
            female_male=utils.cal_male_female(State_male,State_female)
            P_male,P_female=utils.update_param(female_male,P_male,P_female,survive_index=1,\
                pollution_impact=configs.water_pollution_survive_rate,\
                    noise_impact=noise_survive[times],\
                        artificial_impact=configs.artificial_survive_rate)
            State_male,State_female=utils.transition(State_male,State_female,\
                P_male,P_female,female_birth=configs.female_male_birth_Yangtze_River)
            male.append(int(np.sum(State_male)))
            female.append(int(np.sum(State_female)))
            total.append(int(np.sum(State_male))+int(np.sum(State_female)))
            print("echo:",year+1,"male:",male[-1],"female:",\
                female[-1],"total",total[-1])
        
        #plt.subplot(2,3,times+1)
        plt.xlabel('Time/year')
        plt.ylabel('Number')
        utils.draw_smooth_graph(total,name='Noise impact: '+str(water_pollution_survive[times]),start_year=2021)
        plt.legend(loc='upper right')
    plt.show()