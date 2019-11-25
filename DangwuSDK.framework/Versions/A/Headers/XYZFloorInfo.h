//
//  XYZFloorInfo.h
//  XYZ
//
//  Created by bai on 2019/10/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XYZFloorInfo : NSObject

@property(nonatomic, copy) NSString *floorId;
@property(nonatomic, copy) NSString *name;
@property(nonatomic, copy) NSString *alias;
@property(nonatomic, copy) NSString *siteId;

@property(nonatomic, assign) float minX;
@property(nonatomic, assign) float minY;
@property(nonatomic, assign) float maxX;
@property(nonatomic, assign) float maxY;

@end

NS_ASSUME_NONNULL_END
