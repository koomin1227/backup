# -------------------------------------
# [Empty Module #1] Feature Engineering
# -------------------------------------

# -------------------------------------
# Feature Engineering
# -------------------------------------
# 목적: 제공된 36개의 시퀀스 도메인 데이터를 기반으로 유의미한 피처를 추출한다.
# 입력인자: 시간(time) 도메인 Feature 20개 , 주파수(frequency) 도메인 Feature 16개
# 출력인자: 분류모델 학습을 위한 Feature
# -------------------------------------

# ------------------------------------------------------------
# 논문에서 제안하는 Feature Engineering 방법을 따라 feature 추출
# ------------------------------------------------------------
#
# mean(): Mean value
# std(): Standard deviation
# mad(): Median absolute deviation 
# max(): Largest value in array
# min(): Smallest value in array
# sma(): Signal magnitude area
# energy(): Energy measure. Sum of the squares divided by the number of values. 
# iqr(): Interquartile range 
# entropy(): Signal entropy
# arCoeff(): Autorregresion coefficients with Burg order equal to 4
# correlation(): correlation coefficient between two signals
# maxInds(): index of the frequency component with largest magnitude
# meanFreq(): Weighted average of the frequency components to obtain a mean frequency
# skewness(): skewness of the frequency domain signal 
# kurtosis(): kurtosis of the frequency domain signal 
# bandsEnergy(): Energy of a frequency interval within the 64 bins of the FFT of each window.
# angle(): Angle between to vectors.

import sys

# Time domain Feature Extract function

from Feature_engineering import mean_axial,std_axial,mad_axial,max_axial,min_axial, t_sma_axial, t_energy_axial,IQR_axial,entropy_axial, t_arburg_axial, t_corr_axial
from Feature_engineering import mean_mag,std_mag,mad_mag,max_mag,min_mag,t_sma_mag,t_energy_mag,IQR_mag,entropy_mag,t_arburg_mag

# Frequency domain Feature Extract function
from Feature_engineering import f_sma_axial,f_energy_axial,f_max_Inds_axial,f_mean_Freq_axial,f_skewness_and_kurtosis_axial,f_all_bands_energy_axial
from Feature_engineering import f_sma_mag,f_energy_mag,f_max_Inds_mag,f_mean_Freq_mag,f_skewness_mag,f_kurtosis_mag

# Additional Feature Extract function
from Feature_engineering import angle_features

def feature_extractor(time_dictionary,freq_dictionary, condition='train') :
    if condition is 'train' :
        total_data = []
        total_label = []
    elif condition is 'test' :
        total_data = []
        
    for i in tqdm.tqdm(range(len(time_dictionary))) :
        
        time_key = sorted(time_dictionary.keys())[i]
        freq_key = sorted(freq_dictionary.keys())[i]
        
        time_window = time_dictionary[time_key]
        freq_window = freq_dictionary[freq_key]
        
        if condition is 'train' :
            window_user_id= int(time_key[-8:-6]) # extract the user id from window's key
            window_activity_id=int(time_key[-2:]) # extract the activity id from the windows key
        elif condition is 'test' :
            window_user_id= int(time_key[-10:-8]) # extract the user id from window's key
            window_activity_id= 0
        else :
            print("Error")
            sys.exit()
            break;
            
        ##################################################################################
        
        
        # Time domain - Feature extractor - Part 1. axial(X,Y,Z) Features 
        
        #[0,1,2] : 't_body_acc_X', 't_body_acc_Y', 't_body_acc_Z'
        #[3,4,5] : 't_grav_acc_X','t_grav_acc_Y', 't_grav_acc_Z'
        #[6,7,8] : 't_body_acc_jerk_X','t_body_acc_jerk_Y', 't_body_acc_jerk_Z'
        #[9,10,11] : 't_body_gyro_X','t_body_gyro_Y', 't_body_gyro_Z'
        #[12,13,14] : 't_body_gyro_jerk_X', 't_body_gyro_jerk_Y', 't_body_gyro_jerk_Z'
        
        axial_columns = time_window.columns[0:15]
        axial_df = time_window[axial_columns] # X,Y,Z
        
        time_axial_features = []
        
        for col in range(0,15,3) : 
            
            # ------------------------------------------------------------
            # 구현 가이드라인 
            # ------------------------------------------------------------
            # 아래 time_3axial_vector 나타난 Feature를 계산하여야 한다.
            # 각각을 계산하기위한 함수는 'Feature_engineering.py'에 내제되어 있다.
            # ------------------------------------------------------------
            cur_col = axial_columns[col:col+3]
            cur_df = axial_df[cur_col]
            
            mean_vector= mean_axial(cur_df)
            std_vector= std_axial(cur_df)
            mad_vector = mad_axial(cur_df)
            max_vector = max_axial(cur_df)
            min_vector = min_axial(cur_df)
            sma_value = t_sma_axial(cur_df)
            energy_vector = t_energy_axial(cur_df)
            IQR_vector = IQR_axial(cur_df)
            entropy_vector = entropy_axial(cur_df)
            AR_vector = t_arburg_axial(cur_df)
            corr_vector = t_corr_axial(cur_df)
    
            # 40 value per each 3-axial signals
            time_3axial_vector= mean_vector + std_vector + mad_vector + max_vector + min_vector + [sma_value] + energy_vector + IQR_vector + entropy_vector + AR_vector + corr_vector
            
            # append these features to the global list of features
            time_axial_features= time_axial_features+ time_3axial_vector
        
        ##################################################################################
        
        # Time domain - Feature extractor - Part 2. Magnitude Features 
        
        #[15]'t_body_acc_mag'
        #[16]'t_grav_acc_mag'
        #[17]'t_body_acc_jerk_mag'
        #[18]'t_body_gyro_mag'
        #[19]'t_body_gyro_jerk_mag'
        
        mag_columns = time_window.columns[15:]
        mag_columns = time_window[mag_columns]
        
        time_mag_features = []
        
        for col in mag_columns :
            
            # ------------------------------------------------------------
            # 구현 가이드라인 
            # ------------------------------------------------------------
            # 아래 col_mag_values 나타난 Feature를 계산하여야 한다.
            # 각각을 계산하기위한 함수는 'Feature_engineering.py'에 내제되어 있다.
            # ------------------------------------------------------------
#             cur_col = axial_columns[col]
#             cur_df = axial_df[cur_col]
            
            mean_value = mean_mag(mag_columns[col])
            std_value = std_mag(mag_columns[col])
            mad_value = mad_mag(mag_columns[col])
            max_value = max_mag(mag_columns[col])
            min_value = min_mag(mag_columns[col])
            sma_value = t_sma_mag(mag_columns[col])
            energy_value = t_energy_mag(mag_columns[col])
            IQR_value = IQR_mag(mag_columns[col])
            entropy_value = entropy_mag(mag_columns[col])
            AR_vector = t_arburg_mag(mag_columns[col])
            # 13 value per each t_mag_column
            col_mag_values = [mean_value, std_value, mad_value, max_value, min_value, sma_value, 
                              energy_value,IQR_value, entropy_value]+ AR_vector

            # col_mag_values will be added to the global list
            time_mag_features= time_mag_features+ col_mag_values

        
        ##################################################################################
        
        # Frequency domain - Feature extractor - Part 1. axial(X,Y,Z) Features 
        
        #[0,1,2] : 'f_body_acc_X', 'f_body_acc_Y', 'f_body_acc_Z'
        #[3,4,5] : 'f_body_acc_jerk_X','f_body_acc_jerk_Y', 'f_body_acc_jerk_Z'
        #[6,7,8] : 'f_body_gyro_X','f_body_gyro_Y', 'f_body_gyro_Z'
        #[9,10,11] : 'f_body_gyro_jerk_X','f_body_gyro_jerk_Y', 'f_body_gyro_jerk_Z'
        
        axial_columns=freq_window.columns[0:12]
        axial_df=freq_window[axial_columns]
        freq_axial_features=[]
        
        for col in range(0,12,3) :         
            # ------------------------------------------------------------
            # 구현 가이드라인 
            # ------------------------------------------------------------
            # 아래 freq_3axial_features 나타난 Feature를 계산하여야 한다.
            # 각각을 계산하기위한 함수는 'Feature_engineering.py'에 내제되어 있다.
            # ------------------------------------------------------------
            cur_col = axial_columns[col:col + 3]
            cur_df = axial_df[cur_col]
            
            mean_vector= mean_axial(cur_df)
            std_vector= std_axial(cur_df)
            mad_vector = mad_axial(cur_df)
            max_vector = max_axial(cur_df)
            min_vector = min_axial(cur_df)
            sma_value = f_sma_axial(cur_df)
            energy_vector = f_energy_axial(cur_df)
            IQR_vector = IQR_axial(cur_df)
            entropy_vector = entropy_axial(cur_df)
            max_inds_vector = f_max_Inds_axial(cur_df)
            mean_Freq_vector = f_mean_Freq_axial(cur_df)
            skewness_and_kurtosis_vector = f_skewness_and_kurtosis_axial(cur_df)
            bands_energy_vector = f_all_bands_energy_axial(cur_df)

            freq_3axial_features = mean_vector +std_vector + mad_vector + max_vector + min_vector + [sma_value] + energy_vector + IQR_vector + entropy_vector + max_inds_vector + mean_Freq_vector + skewness_and_kurtosis_vector + bands_energy_vector
            freq_axial_features = freq_axial_features+ freq_3axial_features
        
        ##################################################################################
        
        # Frequency domain - Feature extractor - Part 2. Magnitude Features
        
        #[12]'f_body_acc_mag'
        #[13]'f_body_acc_jerk_mag'
        #[14]'f_body_gyro_mag'
        #[15]'f_body_gyro_jerk_mag'
        
        mag_columns=freq_window.columns[12:]
        mag_columns=freq_window[mag_columns]
        
        freq_mag_features = []
        
        for col in mag_columns:
            # ------------------------------------------------------------
            # 구현 가이드라인 
            # ------------------------------------------------------------
            # 아래 col_mag_values에 나타난 Feature를 계산하여야 한다.
            # 각각을 계산하기위한 함수는 'Feature_engineering.py'에 내제되어 있다.
            # ------------------------------------------------------------
            
            mean_value = mean_mag(mag_columns[col])
            std_value = std_mag(mag_columns[col])
            mad_value = mad_mag(mag_columns[col])
            max_value = max_mag(mag_columns[col])
            min_value = min_mag(mag_columns[col])
            sma_value = f_sma_mag(mag_columns[col])
            energy_value = f_energy_mag(mag_columns[col])
            IQR_value = IQR_mag(mag_columns[col])
            entropy_value = entropy_mag(mag_columns[col])
            max_Inds_value = f_max_Inds_mag(mag_columns[col])
            mean_Freq_value = f_mean_Freq_mag(mag_columns[col])
            skewness_value = f_skewness_mag(mag_columns[col])
            kurtosis_value = f_kurtosis_mag(mag_columns[col])
            
            # 13 value per each t_mag_column
            col_mag_values = [mean_value, std_value, mad_value, max_value, 
                              min_value, sma_value, energy_value,IQR_value, 
                              entropy_value, max_Inds_value, mean_Freq_value,
                              skewness_value, kurtosis_value ]
            
            freq_mag_features= freq_mag_features+ col_mag_values
        
        ##################################################################################
        
        # Time domain - Feature extractor - Part 3. Additional Features 
        
        additional_features = angle_features(time_window)
                
        ##################################################################################
        
        total_features = time_axial_features + time_mag_features + freq_axial_features + freq_mag_features + additional_features
        
        total_data.append(total_features)
        if condition is 'train' :
            total_label.append(window_activity_id)
    
    total_data = np.array(total_data)
    if condition is 'train' :
        total_label = np.array(total_label)
    
    if condition is 'train' :
        return total_data, total_label
    elif condition is 'test' :
        return total_data
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
train_data, train_label = feature_extractor(train_time_dictionary_window,train_frequent_dictionary_window,condition='train')
test_data = feature_extractor(test_time_dictionary_window,test_frequent_dictionary_window,condition='test')




































# -------------------------------------
# [Empty Module #2] Data Normalization
# -------------------------------------

# -------------------------------------
# Data Normalization
# -------------------------------------
# 목적: 앞서 구축한 train,test 셋에 대한 Feature를 정규화한다.
# 입력인자: train 셋에서 추출된 Feature, test 셋에서 추출된 Feature
# 출력인자: 정규화된 Feature Vector
# -------------------------------------


from sklearn.preprocessing import MinMaxScaler

# ------------------------------------------------------------
# 구현 가이드라인 
# ------------------------------------------------------------
# sklearn에서 제공하는 MinMaxScaler를 사용해 데이터 정규화를 진행한다.
# (MinMaxScaler가 아닌 다른 정규화를 사용할 수 있다.)
# ------------------------------------------------------------
mm = MinMaxScaler()
mm_train = mm.fit_transform(train_data)
mm_test = mm.transform(test_data)















































# -------------------------------------
# [Empty Module #3] RandomForest를 이용한 분류
# -------------------------------------

# -------------------------------------
# RandomForest를 이용한 분류
# -------------------------------------
# 목적: 앞서 완성한 train/test Feature를 RandomForest를 이용해 분류한다.
# 추가 안내 : 리더보드의 베이스라인은 random_state를 0으로 하였다.
# 입력인자: Feature vector(train/test)
# 출력인자: 분류결과
# -------------------------------------

from sklearn.ensemble import RandomForestClassifier

# ------------------------------------------------------------
# 구현 가이드라인 
# ------------------------------------------------------------
# sklearn에서 제공하는 RandomForest를 사용해 분류를 진행한다.
# (RandomForest를가 아닌 다른 분류모델을 사용할 수 있다.)
# ------------------------------------------------------------
clf = RandomForestClassifier(max_depth=2, ran)
clf.fit(mm_train,train_label)
y_pred = clf.predict(mm_test)
