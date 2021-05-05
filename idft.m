%file name : idft.m
%Inverse Discrete Fourier Transform (IDFT) of the sequence. 
%																MatLab Version 5.2

% This Matlab program calculates the IDFT of the sequence.
% Input:	DFT X(k)
% Ouput:	Display of sequence x(n)
%-------------------------------------------------------------------------
%------ next part accepts DFT X(k) ---------------------------------------

Xk = input('Enter the DFT X(k)= ');		% accept DFT X(k)

%------ Next part calculates IDFT x(n) -----------------------------------

[N,M] = size(Xk);		%		These statements determine
if M~=1,					%		the size of the vector X(k)
   Xk = Xk.';			%		suitable for evaluating 
   N = M;				%		the IDFT. Here 'N' is the length
end						%					of the DFT
xn = zeros(N,1);		% The sequence values are initialized to zeros
k = 0:N-1;				% Index k varies from 0 to N-1
for n = 0:N-1								%	This 'for' loop implements
   xn(n+1) = exp(j*2*pi*k*n/N)*Xk;	%	the IDFT formula and calculates
end											%	x(n) for n = 0 to N-1
xn = xn/N;									%  Divide by N as per IDFT formula	
disp(xn);				%	display sequence on the screen

%--------------- End of the program -------------------------------------
