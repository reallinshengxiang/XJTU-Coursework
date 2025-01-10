/*1. Use Marco*/
#include "mex.h" 
/* 2. The computational routine */
class arrayProd {
private:
    double multiplier;              /* input scalar */
    double *inMatrix;               /* 1xN input matrix */
    size_t ncols;                   /* size of matrix */
    double *outMatrix;              /* output matrix */    
public:
arrayProd();
~arrayProd();
arrayProduct(double x, double *y, double *z, mwSize n);       
};

void arrayProd::arrayProduct(double x, double *y, double *z, mwSize n)
    {
        mwSize i;
        /* multiply each element y by x */
        for (i=0; i<n; i++) {
            z[i] = x * y[i];
        }
    }
/* 3. The gateway function */
void mexFunction( int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    arrayProd example;            /* calculate object */
     /* check for proper number of arguments */
    if(nrhs!=2) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs","Two inputs required.");
    }
    if(nlhs!=1) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs","One output required.");
    }
    /*4. make sure the first input argument is scalar */
    if( !mxIsDouble(prhs[0]) || mxIsComplex(prhs[0]) ||
         mxGetNumberOfElements(prhs[0])!=1 ) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:notScalar","Input multiplier must be a scalar.");
    }
    /* check that number of rows in second input argument is 1 */
    if(mxGetM(prhs[1])!=1) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:notRowVector","Input must be a row vector.");
    }
/* 5. get the value of the scalar input  */
    multiplier = mxGetScalar(prhs[0]);
/* create a pointer to the real data in the input matrix  */
    inMatrix = mxGetPr(prhs[1]);
    /* get dimensions of the input matrix */
    ncols = mxGetN(prhs[1]);
    /* create the output matrix */
    plhs[0] = mxCreateDoubleMatrix(1,(mwSize)ncols,mxREAL);
    /* get a pointer to the real data in the output matrix */
    outMatrix = mxGetPr(plhs[0]);
    /* 6. call the computational routine */
    example.arrayProduct(multiplier,inMatrix,outMatrix,(mwSize)ncols);
}