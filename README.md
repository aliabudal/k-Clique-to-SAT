
# k-Clique to SAT Reduction:
The objective is to identify a polynomial reduction from the kClique problem,
to the SAT problem, its implementation in a programming language, and the comparison
of the running times between a script that solves kClique in exponential time and another that
solves the problem using a SAT solver.

# Structure:
1. We write an algorithm that runs in exponential time to solve the problem kClique. (Below we will refer to this as "backtracking", but you will not be limited to writing a backtracking algorithm, you can implement any algorithm that solves the problem in exponential time and correctly).
2. Finding a polynomial transformation 𝑇, by which we can reduce the kClique problem to the SAT problem and to implement it in a programming language. The reduction must be implemented both in a programming language and on paper, where you will demonstrate its correctness and the fact that it is polynomial.
3. Comparison of the execution time between the algorithm that runs in exponential time (the one implemented at 1) and the algorithm that implements the polynomial transformation + SAT solver provided in the skeleton. This "speedup" will be calculated by the checker on 3 categories of tests (divided based on certain criteria that you have identified). Your goal is to motivate in the README why in some cases the speedup is a good one and the reduction is favorable and why is it not in other cases.
4. BONUS: for requirement 3, you can include in the README graphics that highlight the connection between speedup and the input of the problem (the size of the clique, the number of nodes, the number of edges, or any other metric that you think would influence execution time). You can also create your own tests, highlighting what exactly does the running time of the 2 algorithms depend on. The bonus will be offered subjectively to each student depending on the quality of the explanations offered and their support through graphs / tests, that is, there will be partial scores.

# Requirements:
```python
pip install -r requirements.txt
