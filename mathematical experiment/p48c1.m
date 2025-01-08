he=0;
jiecheng=1;
for i=1:1:100
    he=he+1;
    jiecheng=jiecheng*i;
end
he
jiecheng

syms x he a b
for k=1:10
    he=he+k*(x-2)*b+(k-1)*(x-a)^2;
end
expand(he)