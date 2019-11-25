//
//  XYZLocation.h
//  XYZ
//
//  Created by mq on 2018/5/31.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface XYZLocation : NSObject

@property(nonatomic, assign) double coordinateX;
@property(nonatomic, assign) double coordinateY;
@property(nonatomic, readonly, assign) double latitude;
@property(nonatomic, readonly, assign) double longitude;
@property(nonatomic, readonly, strong) NSString *floorId;
@property(nonatomic, readonly, assign) double certainty;
@property(nonatomic, readonly, assign) double heading;

- (instancetype)initWithCoordinateX:(CGFloat)coordinateX
             coordinateY:(CGFloat)coordinateY
                latitude:(CGFloat)latitude
               longitude:(CGFloat)longitude
                floorId:(NSString*)floorId
               certainty:(CGFloat)certainty
                 heading:(CGFloat)heading;

- (void)setHeading:(double)heading;

@end
