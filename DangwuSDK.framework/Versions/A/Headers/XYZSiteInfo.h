//
//  XYZSiteInfo.h
//  XYZ
//
//  Created by bai on 2019/10/11.
//

#import <Foundation/Foundation.h>
@class XYZFloorInfo;

NS_ASSUME_NONNULL_BEGIN

@interface XYZSiteInfo : NSObject

@property (nonatomic, copy) NSString *siteId;
@property (nonatomic, copy) NSString *address;
@property (nonatomic, copy) NSString *city;
@property (nonatomic, copy) NSString *provinceName;
@property (nonatomic, copy) NSString *district;

@property (nonatomic, copy) NSArray<XYZFloorInfo *> *floorArray;

@end

NS_ASSUME_NONNULL_END
