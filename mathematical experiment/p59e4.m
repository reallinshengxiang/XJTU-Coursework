n=round(rand()*99)+1;
i=1;
while i<=7
    x=input('x=');
    if(x==n)
        fprintf('You win!\n');
        break;
    elseif(x>n)
        fprintf('High\n');
    else
        fprintf('Low\n');
    end
    i=i+1;
end