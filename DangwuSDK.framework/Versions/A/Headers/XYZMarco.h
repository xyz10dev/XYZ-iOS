//
//  XYZMarco.h
//  XYZ
//
//  Created by bai on 2019/10/21.
//

#ifndef XYZMarco_h
#define XYZMarco_h

static NSString * const kXYZToken = @"kXYZToken";

#if DEBUG
#define XYZLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#define XYZLog(fmt, ...) while(0){}
#endif

// 屏幕宽高
#define kXYZScreenWidth ([UIScreen mainScreen].bounds.size.width)
#define kXYZScreenHeight ([UIScreen mainScreen].bounds.size.height)
// 状态栏高度
#define kXYZStatusHeight ([UIApplication sharedApplication].statusBarFrame.size.height)

// 颜色
#define XYZHexAColor(c,a) ([UIColor colorWithRed:((float)((c & 0xFF0000) >> 16))/255.0 green:((float)((c & 0xFF00) >> 8))/255.0 blue:((float)(c & 0xFF))/255.0 alpha:(a)])
#define XYZHexColor(c) XYZHexAColor(c, 1.0)

#define XYZRamdomColor [UIColor colorWithRed:arc4random_uniform(255)/255.0 green:arc4random_uniform(255)/255.0 blue:arc4random_uniform(255)/255.0 alpha:1.0]


#endif /* XYZMarco_h */
