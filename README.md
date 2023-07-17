# Default Probability by Using the Merton Model for Structural Credit Risk
This project uses equity prices to estimate default probabilities by using newton raphson method to solve nonlinear simultaneous equations in the merton model. 

In 1974, Merton proposed a model where a company’s equity is an option on the assets of the company.9 Suppose, for simplicity, that a firm has one zero-coupon bond outstanding and that the bond matures at time T. Define:

V0 : Value of company’s assets today
VT : Value of company’s assets at time T E0 : Value of company’s equity today
ET : Value of company’s equity at time T D: Debt repayment due at time T
V : Volatility of assets (assumed constant) E : Instantaneous volatility of equity.
If VT < D, it is (at least in theory) rational for the company to default on the debt at time T . The value of the equity is then zero. If VT > D, the company should make the debt repayment at time T and the value of the equity at this time is VT  D. Merton’s model, therefore, gives the value of the firm’s equity at time T as
ET 1⁄4 maxðVT  D; 0Þ
This shows that the equity is a call option on the value of the assets with a strike price
