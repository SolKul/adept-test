import numpy as np

def michaelis(conce,V_max,K_m):
    """
    ミカエリス・メンテン式。反応率を算出する。
    """
    return V_max*conce/(K_m+conce)


def compute_j(matrix_con,p_x=np.array([[0.5],[0.5]])):
    """
    モデル関数について微分し、ヤコビアンを計算する。

    Args:
        matrix_con : 基質濃度の1次元配列
    """
    # 要素が0の縦2、横1の行列を用意
    dx_base=np.zeros([2,1])
    # 微小距離を定義
    dx=1e-3
    # ヤコビアンのリストを設定
    jacobian=[]
    # パラメータの数分ループ
    for i in range(2):
        dx_array=dx_base.copy()
        dx_array[i,0]=dx
        # p_xから微小距離だけ移動したベクトルを作る。
        p_x_d=p_x+dx_array
        # ミカエリス・メンテン式で反応率を計算する。
        v_p=michaelis(matrix_con,p_x_d[0,0],p_x_d[1,0])

        p_x_d=p_x-dx_array
        v_m=michaelis(matrix_con,p_x_d[0,0],p_x_d[1,0])

        jacobian.append((v_p-v_m)/dx/2)

    return np.array(jacobian).T

# 測定データを用意
matrix_con=np.array([0.038,0.194,0.425,0.626,1.253,2.500,3.740])
cons_rate=np.array([0.050,0.127,0.094,0.2122,0.2729,0.2665,0.3317])

print(compute_j(matrix_con).T)