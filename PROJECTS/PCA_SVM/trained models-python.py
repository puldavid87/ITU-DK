# -*- coding: utf-8 -*-
"""
Created on Mon Oct 25 11:29:38 2021

@author: paur
"""

from sklearn.decomposition import PCA
from sklearn.datasets import load_iris
from micromlgen import port

if __name__ == '__main__':
    X = load_iris().data
    pca = PCA(n_components=2, whiten=False).fit(X)

    print(port(pca))



'T-SNE'

from sklearn.manifold import TSNE
import numpy as np
X = load_iris().data
tsne = TSNE(n_components=2, perplexity=10, random_state=12).fit_transform(X)
    print(port(tsne))

X = np.array([[0, 0, 0], [0, 1, 1], [1, 0, 1], [1, 1, 1]])
X_embedded = TSNE(n_components=2, perplexity=10, random_state=12).fit_transform(X)