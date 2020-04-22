//
//  XYZLocationManager.h
//  XYZ
//
//  Created by mq on 2018/5/14.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "XYZFloorInfo.h"
#import "XYZSiteInfo.h"
#import "XYZLocation.h"
#import "XYZPoisNotify.h"
#import "XYZPoiEventNotify.h"
#import "XYZMarco.h"
#import "XYZUserActsNotify.h"

NS_ASSUME_NONNULL_BEGIN

@protocol XYZLocationManagerDelegate;

@interface XYZLocationManager : NSObject

@property (nonatomic, copy) NSString *appKey;
@property (nonatomic, weak) id <XYZLocationManagerDelegate> _Nullable delegate;
@property (nonatomic, copy) NSDictionary *navPathDictionary;

/**
 初值设置
 定位开始之前，可以设置初始值
 */
@property (nonatomic, copy) NSString *siteId;
@property (nonatomic, copy) NSString *floorId;
@property (nonatomic, assign) CGPoint coordinate;

/**
 负责管理十域定位服务的单例

 @return XYZLocationManager单例
 */
+ (instancetype)defaultManager;

/**
 开始请求定位
 */
- (void)startUpdatingLocationWithMode:(XYZFollowMode)mode;

/**
 结束请求定位
 */
- (void)stopUpdatingLocation;

/**
 设备id
 */
+ (NSString *)deviceId;

/**
 本次定位的traceid

 @return traceid
 */
- (NSString *)currentTraceId;


#pragma mark - 服务器交互

/**
 定位过程中，手动设置场馆

 @param siteId 场馆id
 */
- (void)manualSetSite:(NSString *)siteId;

- (void)sendNavPath:(NSDictionary *)navPathDictionary;


/**
 定位过程中，手动设置楼层
 
 @param floorId floorId
 */
- (void)manualSetFloor:(NSString *)floorId;


/**
 获取场馆信息

 @param siteId 场馆id
 @param callback 场馆信息回调
 */
- (void)getSiteInfoWithSiteId:(NSString *)siteId callback:(void (^)(XYZSiteInfo *, NSError *))callback;


/**
 获取楼层信息

 @param floorId 楼层id
 @param callback 场馆信息回调
 */
- (void)getFloorInfoWithFloorId:(NSString *)floorId callback:(void (^)(XYZFloorInfo *, NSError *))callback;


/**
 定位过程中，自动设置楼层
 */
- (void)autoSetFloor;


/**
 获取当前位置附近的Poi列表

 @param siteId 场馆id
 @param callback Poi列表，错误信息
 */
- (void)getPoiListWithSiteId:(NSString *)siteId
                    callback:(void (^)(XYZPoisNotify *, NSError *))callback;

/**
 离线到店分析：开始采集数据

 @param siteId 场馆ID
 @param callback iBeacon扫描异常回调
 */
- (void)startTrackWithSiteId:(NSString *)siteId callback:(void (^)(NSError *))callback;


/**
 离线到店分析：结束采集数据，上传数据用于数据分析，请求分析结果

 @param callback 到店分析结果回调
 */
- (void)stopTrackWithBlock:(void (^)(XYZPoiEventNotify *, NSError *))callback;

@end



#pragma mark - XYZLocationManagerDelegate

@protocol XYZLocationManagerDelegate <NSObject>
@optional

- (void)didGetTraceID:(NSString *)traceID;
/**
 服务器发送notify类型的数据包时会调用
 
 @param location XYZLocation
 */
- (void)didUpdateLocation:(nonnull XYZLocation *)location;

/**
 服务器发送notify数据包，且返回的楼层和当前楼层不一样时会调用
 
 @param floorId 楼层id
 */
- (void)didEnterFloorId:(nonnull NSString *)floorId;


/// 检测到用户的进店和离店事件时会调用该方法
/// @param notify 进店、离店事件
- (void)didDetectedUserAct:(XYZUserActsNotify *)notify;

/**
 error

 @param error error
 */
- (void)didOccurError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
