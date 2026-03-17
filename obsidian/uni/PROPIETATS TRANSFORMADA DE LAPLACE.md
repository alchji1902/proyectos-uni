### Taula de Transformades de Laplace ($x(t) \to X(s)$)

$$
\begin{array}{|l|c|c|c|}
\hline
\text{Nom} & \text{Funció Temps } x(t) & \text{Transformada } X(s) & \text{Domini / Condició} \\ \hline
\text{Impuls unitari} & \delta(t) & 1 & \text{Tot } s \\ \hline
\text{Impuls desplaçat} & \delta(t-a) & e^{-as} & a \ge 0 \\ \hline
\text{Escaló unitari} & u(t) & \frac{1}{s} & Re(s) > 0 \\ \hline
\text{Rampa} & t & \frac{1}{s^2} & Re(s) > 0 \\ \hline
\text{Potència} & t^n & \frac{n!}{s^{n+1}} & n \in \mathbb{N}, s > 0 \\ \hline
\text{Exponencial} & e^{at} & \frac{1}{s-a} & Re(s) > a \\ \hline
\text{Producte } t^n e^{at} & t^n e^{at} & \frac{n!}{(s-a)^{n+1}} & Re(s) > a \\ \hline
\text{Sinus} & \sin(\omega t) & \frac{\omega}{s^2 + \omega^2} & Re(s) > 0 \\ \hline
\text{Cosinus} & \cos(\omega t) & \frac{s}{s^2 + \omega^2} & Re(s) > 0 \\ \hline
\text{Sinus hiperbòlic} & \sinh(at) & \frac{a}{s^2 - a^2} & Re(s) > |a| \\ \hline
\text{Cosinus hiperbòlic} & \cosh(at) & \frac{s}{s^2 - a^2} & Re(s) > |a| \\ \hline
\text{Exp. amortida (sin)} & e^{at} \sin(\omega t) & \frac{\omega}{(s-a)^2 + \omega^2} & Re(s) > a \\ \hline
\text{Exp. amortida (cos)} & e^{at} \cos(\omega t) & \frac{s-a}{(s-a)^2 + \omega^2} & Re(s) > a \\ \hline
\end{array}
$$

### Propietats i Teoremes Operacionals

$$
\begin{array}{|l|c|c|}
\hline
\text{Propietat} & \text{Domini del Temps } x(t) & \text{Domini de Laplace } X(s) \\ \hline
\text{Linealitat} & a \cdot x(t) + b \cdot y(t) & a \cdot X(s) + b \cdot Y(s) \\ \hline
\text{1a Traslació (en } s) & e^{at} x(t) & X(s-a) \\ \hline
\text{2a Traslació (en } t) & x(t-a) u(t-a) & e^{-as} X(s) \\ \hline
\text{Canvi d'escala} & x(at) & \frac{1}{a} X\left(\frac{s}{a}\right) \\ \hline
\text{Derivada Primera} & x'(t) & s X(s) - x(0) \\ \hline
\text{Derivada Segona} & x''(t) & s^2 X(s) - s x(0) - x'(0) \\ \hline
\text{Integral} & \int_{0}^{t} x(\tau) d\tau & \frac{1}{s} X(s) \\ \hline
\text{Multiplicació per } t & t x(t) & -X'(s) \\ \hline
\text{Divisió per } t & \frac{x(t)}{t} & \int_{s}^{\infty} X(u) du \\ \hline
\text{Convolució} & (x * y)(t) & X(s) \cdot Y(s) \\ \hline
\text{Valor Inicial} & t \to 0^+ & \lim_{s \to \infty} s X(s) \\ \hline
\text{Valor Final} & t \to \infty & \lim_{s \to 0} s X(s) \\ \hline
\end{array}
$$
