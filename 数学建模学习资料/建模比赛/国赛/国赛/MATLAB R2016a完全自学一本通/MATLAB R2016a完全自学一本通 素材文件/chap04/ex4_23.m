a = 0:0.002:1;
b = humps(a);
plot(a,b)
function b = humps
b = 1./((x-.3).^2 + .01) + 1./((x-.9).^2 + .04) - 6;		%在区间0 x 1求此函数的值
