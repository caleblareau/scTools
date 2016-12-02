context("KNN Dist Graph Works")

test_that("KNN works", {
    X <- matrix(rnorm(100), nrow = 5)
    y <- calcKNNgraph(X, 2)
    expect_equal(dim(y)[2], 2)
})

