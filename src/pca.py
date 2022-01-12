import numpy as np
import matplotlib.pyplot as plt

def pca(arr,n_components=10):
    mean = arr.mean(axis=0)
    arr -= mean
    M = len(arr)
    C = np.matmul(arr.T,arr)/M
    val,vec=np.linalg.eigh(C)
    sorted_index = list(reversed(np.argsort(val)))[:n_components]
    vec = vec[sorted_index]
    R = np.matmul(arr,vec[0])
    return R

def main():
    arr = np.array([
        [1,1],
        [1,3],
        [2,3],
        [4,4],
        [2,4]
    ]).astype(np.float32)
    R = pca(arr)
    plt.xlabel("X")
    plt.ylabel("Y")
    ax = plt.gca()
    ax.spines['right'].set_color('none')
    ax.spines['top'].set_color('none')
    # ax.xaxis.set_ticks_position('bottom')
    # ax.yaxis.set_ticks_position('left')
    ax.spines['bottom'].set_position(('data',0))
    ax.spines['left'].set_position(('data',0))
    plt.scatter(arr[:,0],arr[:,1],color='r')
    plt.plot(R,R,color='b')
    plt.show()



if __name__ == '__main__':
    main()
