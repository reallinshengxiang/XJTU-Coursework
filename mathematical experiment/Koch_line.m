function Koch_line(time, A)
w1 = [1.0/3, 0; 0, 1.0/3]; t1 = [0, 0];
w2 = [1.0/6, -sqrt(3)/6; sqrt(3)/6, 1.0/6]; t2 = [1.0/3, 0];
w3 = [1.0/6, sqrt(3)/6; -sqrt(3)/6, 1.0/6]; t3 = [1.0/2, sqrt(3)/6];
w4 = [1.0/3, 0; 0, 1.0/3]; t4 = [2.0/3, 0];
for i=1:time
    test_A = zeros(2, 1+4^i);
    [m,n] = size(A);
    for j=1:n-1 
        test_A(:, (j-1)*4+1) = A(:, j); 
        test_A(:, (j-1)*4+2) = 1/3 * (A(:, j+1)-A(:, j)) + A(:, j); 
        test_A(:, (j-1)*4+3) = w2*(A(:, j+1)-A(:, j)) + A(:, j) + 1/3 * (A(:, j+1)-A(:, j));
        test_A(:, (j-1)*4+4) = 2/3 * (A(:, j+1)-A(:, j)) + A(:, j);
    end
    test_A(:, end) = A(:, end);
    A = test_A;
end
figure,line(A(1, :), A(2, :))
axis([0 1 0 1])
