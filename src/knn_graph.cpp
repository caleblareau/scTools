#include <Rcpp.h>
using namespace Rcpp;

double euc (NumericVector x, NumericVector y){
  int n = y.length();
  double total = 0;
  for (int i = 0; i < n ; ++i) {
    total += pow(x(i)-y(i),2.0);
  }
  total = sqrt(total);
  return total;
}

//' Calculate k Nearest Neighbors from some distance metric
//'
//' This function returns a logical vector identifying if
//' there are leading NA, marking the leadings NA as TRUE and
//' everything else as FALSE.
//'
//' @param x An m x n numeric matrix
//' @param k The number of nearest neighbors to return
//' per sample
//' @return An m x k matrix of indicies 1...k of the
//' nearest neighbors for the specified row.
//' @export
// [[Rcpp::export]]
NumericMatrix calcKNNgraph (NumericMatrix x, int k){
  int outrows = x.nrow();
  int outcols = k;
  NumericMatrix out(outrows,outcols);

  for (int i = 0 ; i < outrows - 1; i++){
    for (int j = i + 1  ; j < outcols ; j ++) {
      NumericVector v1 = x.row(i);
      NumericVector v2 = x.row(j-1);
      double d = euc(v1, v2);
      out(j-1,i) = d;
      out(i,j-1)= d;
    }
  }
  return (out) ;
}
