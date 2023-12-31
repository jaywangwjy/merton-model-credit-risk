# Default Probability by Using the Merton Model for Structural Credit Risk
This project uses equity prices to estimate default probabilities by using Newton-Raphson method to solve nonlinear simultaneous equations in the Merton model. It is a C++ implementation of the questions from Hull's book "Options, Futures, and Other Derivatives" chapter 24.6  

In 1974, Merton proposed a model where a company’s equity is an option on the assets of the company.9 Suppose, for simplicity, that a firm has one zero-coupon bond outstanding and that the bond matures at time T. Define:

V0 : Value of company’s assets today<br>
VT : Value of company’s assets at time T <br> 
E0 : Value of company’s equity today<br>
ET : Value of company’s equity at time T D: Debt repayment due at time T<br>
sigma V: Volatility of assets (assumed constant)<br>
sigma E: Instantaneous volatility of equity <br> <br>
If VT < D, it is (at least in theory) rational for the company to default on the debt at time T . The value of the equity is then zero. If VT > D, the company should make the debt repayment at time T and the value of the equity at this time is VT minus D. Merton’s model, therefore, gives the value of the firm’s equity at time T as: _ET = max(VT - D; 0)_ <br> 
This shows that the equity is a call option on the value of the assets with a strike price equal to the repayment required on the debt. The Black–Scholes–Merton formula gives the value of the equity today as: 
<img width="617" alt="Screenshot 2023-07-18 at 4 37 54 PM" src="https://github.com/jaywangwjy/merton-model-credit-risk/assets/139752570/e53cb844-f2f9-427a-87ae-211149be5144">

The value of the debt today is V0 minus E0. <br>
The risk-neutral probability that the company will default on the debt is N(d2). 
To calculate this, we require V0 and sigma V. Neither of these are directly observable. However, if the company is publicly traded, we can observe E0. We can also estimate sigma E from historical data or options. From Itoˆ ’s lemma, <br>

<img width="328" alt="Screenshot 2023-07-18 at 4 38 22 PM" src="https://github.com/jaywangwjy/merton-model-credit-risk/assets/139752570/f5fb4ddb-6cda-46a2-b0f4-bfd049af66ae">

This provides another equation that must be satisfied by V0 and sigma V. These two screenshots provide a pair of simultaneous equations that can be solved for V0 and sigma V. Since this is a system of non-linear simultaneous equations, we can use an iterative method like the Newton-Raphson method. Using the given equations, we calculate partial derivatives and the Jacobian. We make an initial guess (1) at the solution and then use the Newton-Raphson equation to get a better solution. 
