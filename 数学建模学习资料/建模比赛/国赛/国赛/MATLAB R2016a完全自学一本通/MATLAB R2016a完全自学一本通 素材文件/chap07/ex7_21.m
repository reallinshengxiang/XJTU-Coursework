syms x y;
		f=sym('x^2+x*y+y^2')
		x=2
		subs(f)
		y=2
		subs(f)
		subs(f,'t^2')
		subs(f,{'x','y'},{3,4})
