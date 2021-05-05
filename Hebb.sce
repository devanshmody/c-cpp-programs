n=input("Number of input pattern");
x=[]
c=1;
for i=1:n
     a=input("Enter a pattern");
     x=cat(1,x,a)
end
 wtmat=input("Enter wight matrix");
 for i=1:n
     net=0;
      for j=1:length(wtmat);
          net=net+wtmat(j)*x(i,j);
      end
      r=sign(net);
      for j=1:length(wtmat)
          delta(j)=r*c*x(i,j)
 end
  wtmat=wtmat+delta';
   disp(wtmat);
  end
