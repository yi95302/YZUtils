//
//  YZUtilsConstant.h
//  paintColor
//
//  Created by qazx on 2019/1/10.
//  Copyright © 2019年 qazx. All rights reserved.
//

#import <UIKit/UIKit.h>

/// 是否为刘海屏
static bool YZNotchPhone(void){
    static BOOL isNotch;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        if (@available(iOS 11.0, *)) {
            UIEdgeInsets safeAreaInsets = [UIApplication sharedApplication].keyWindow.safeAreaInsets;
            isNotch = safeAreaInsets.bottom > 20;
        } else {
            isNotch = ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO);
        }
    });
    return isNotch;
}

/// StatusBar高度
static inline CGFloat StatusBarHeight(void){
    return YZNotchPhone()? 44.f : 20.f;
}

/// Tabbar高度
static inline CGFloat TabbarHeight(void){
    return YZNotchPhone()? 82.f : 49.f;
}

/// 底部安全区域高度
static inline CGFloat SafeAreaBottomHeight(void){
    return YZNotchPhone()? 34.f : 0.f;
}


#define  kIS_iPhoneX             YZNotchPhone()
#define  kStatusBarHeight       StatusBarHeight()
#define  kNavigationBarHeight   44.0f
#define  kTabbarHeight          TabbarHeight()
#define  kSafeAreaBottomHeight  SafeAreaBottomHeight()

