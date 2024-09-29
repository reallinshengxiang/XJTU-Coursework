clear;
clc;
oushuhe=0;
jishuhe=0;
i=1;
while i<1000
    if mod(i,2)==0
        oushuhe=oushuhe+i;
    else
        jishuhe=jishuhe+i;
    end
    i=i+1;
end
oushuhe
jishuhe