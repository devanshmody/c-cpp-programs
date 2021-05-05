//NAND
x1=[0,0,1,1];
x2=[0,1,0,1];
w1=[-10];
w2=[-10];
t=-15;
n=4;
for i=1:n
    y(i)=(w1*x1(i))+(w2*x2(i));
   
if y(i)<t then
    y(i)=0;
else
    y(i)=1;
end
end;
disp(y);
plot(y);


