format rat;
h=zeros(8);
for i=1:8
    for j=1:8
        h(i,j)=1/(i+j-1);
    end
end
h
