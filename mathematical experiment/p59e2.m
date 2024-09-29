n=input('输入一个正偶数n=');
for i=3:n-3
    if isprime(i)&isprime(n-i)&i<n-i
        fprintf('%d=%d+%d\n',n,i,n-i);
    end
end