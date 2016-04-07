function [q,qd,qdd]=serpenoid(n,a,b,c,w)
% ? n el n?mero de grados de libertad del robot,
% ? a es el grado de onludaci?n de la curva serpenoide,
% ? b es el n?mero de periodos por unidad de longitud de la curva serponide,
% ? c controla la direcci?n de movimiento del robot serpentino, y
% ? w es la velocidad angular de propagaci?n de la curva serpenoide.
  pt = 100;
  q = zeros(pt,n-1);
  qd = zeros(pt,n-1);
  qdd = zeros(pt,n-1);
  
  tmp = 1;
  for t = 0.1:0.1:10
    pos = zeros(n-1,1);
    vel = zeros(n-1,1);
    acc = zeros(n-1,1);
    for i = 1 : n-1
        pos(i) = a * sin((w * (t)) + (i-1) * b) + c;
        vel(i) = a * w * cos(w * t * (i-1) * b);
        acc(i) = -a * w^2 * sin(w * t * (i-1) * b);
    end;
    q(tmp,:) = pos;
    qd(tmp,:) = vel;
    qdd(tmp,:) = acc;
    tmp = tmp + 1;
  end;
end
