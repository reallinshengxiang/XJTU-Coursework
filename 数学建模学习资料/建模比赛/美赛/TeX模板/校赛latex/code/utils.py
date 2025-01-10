from math import exp
import numpy as np
import configs
from scipy.interpolate import make_interp_spline
from matplotlib import pyplot as plt

def f(age):
    if age<5:
        return 0
    elif 5<=age and age<16:
        return 0.0227*(age-11)
    else:
        return 0.25

def s(age,a=configs.A,b=configs.B):
    return exp(-(a+b*f(age)))

def p(female_male):
    if female_male<2/3:
        return 1
    else:
        return 3*(1-female_male)

def init_param(State_male,State_female,female_male=configs.initial_female_male,\
    number=configs.initial_number):
    for i in range(configs.Max_age):
        State_male[i]=number*\
            (1-female_male)*\
                configs.initial_age_distribution[i]
        State_female[i]=number*\
            female_male*\
                configs.initial_age_distribution[i]
    return State_male,State_female

def cal_male_female(State_male,State_female):
    male=np.sum(State_male)
    female=np.sum(State_female)
    return female/(male+female)

def update_param(female_male,P_male,P_female,\
    survive_index=configs.survive_index,pollution_impact=1,noise_impact=1,\
        artificial_impact=1):
    # 首先算出生率
    for i in range(4,16):
        P_female[i,0]=p(female_male)*pollution_impact
    # 再计算生存率
    for i in range(1,16):
        P_male[i-1,i]=min(1,configs.survive_rate_male[i]\
            /configs.survive_rate_male[i-1]*s(i-1)\
                *survive_index*artificial_impact)
        P_female[i-1,i]=min(1,configs.survive_rate_female[i]\
            /configs.survive_rate_female[i-1]*s(i-1)\
                *survive_index*artificial_impact)
        # print(P_male[i-1,i],P_female[i-1,i])
        # input()
    # 噪声对幼豚的影响
    for i in range(1,5):
        P_male[i-1,i]*=noise_impact
        P_female[i-1,i]*=noise_impact
    return P_male,P_female

def transition(State_male,State_female,P_male,P_female,\
    female_birth=configs.female_male_birth):
    State_male=np.dot(State_male,P_male)
    State_female=np.dot(State_female,P_female)
    State_male[0]=State_female[0]*(1-female_birth)
    State_female[0]*=female_birth
    #print(State_male[0],State_female[0])
    return State_male,State_female

def draw_smooth_graph(param,name='name',start_year=2015):
    x=range(start_year,len(param)+start_year)
    x_smooth = np.linspace(start_year,len(param)+start_year,300)
    y_smooth = make_interp_spline(x,param)(x_smooth)
    plt.plot(x_smooth,y_smooth,label=name)
    plt.xlim(start_year,len(param)+start_year)