# 当午SDK iOS 开发集成文档

## 准备工作

### 获取AppKey

请联系工作人员。

## Quick Start

### CocoaPods集成

集成环境：iOS8及以上
在Podfile文件中添加以下代码：

```
pod 'DangwuSDK', '~> 1.3.2'
```

保存并执行pod install命令，然后用后缀为`.xworkspace`的文件打开工程。


### SDK对接

打开系统定位服务，在info.plist文件中添加`NSLocationAlwaysAndWhenInUseUsageDescription`和`NSLocationWhenInUseUsageDescription`。

在AppDelegate中引入`#import <DangwuSDK/XYZLocationManager.h>`，并在didFinishLaunchingWithOptions方法中设置appKey。

```
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    ...
    // 十域定位服务认证，获取token
    [XYZLocationManager defaultManager].appKey = @"xxxxxxxx";
    ...
}
```

在需要使用定位服务的页面，遵守XYZLocationManagerDelegate，并实现其中的方法：

```

// 设置十域定位服务代理
[XYZLocationManager defaultManager].delegate = self;
```

```
// 位置坐标更新回调
- (void)didUpdateLocation:(XYZLocation *)location;

// 切换楼层回调
- (void)didEnterFloorId:(NSString *)floorId;

// 定位内部错误回调
- (void)didOccurError:(NSError *)error;
```

添加以下代码，开始定位：

```
// 开始定位
[[XYZLocationManager defaultManager] startUpdatingLocation];
```

```
// 关闭室内定位
[[XYZLocationManager defaultManager] stopUpdatingLocation];
```

## SDK API

### XYZLocationManager

- 获取定位服务的单例
```
+ (instancetype)defaultManager;
```

- 设置App key
```
@property (nonatomic, copy) NSString *appKey;
```

- 开始定位
```
- (void)startUpdatingLocation;
```

- 获取本次定位的traceID
```
- (NSString *)currentTraceId;
```

- 获取deviceID
```
+ (NSString *)deviceId;
```

- 手动设置场馆
```
- (void)manualSetSite:(NSString *)siteId;
```

- 获取场馆信息
```
- (void)getSiteInfoWithSiteId:(NSString *)siteId callback:(void (^)(XYZSiteInfo *, NSError *))callback;
```

- 手动设置楼层
```
- (void)manualSetFloor:(NSString *)floorId;
```

- 自动设置楼层
```
- (void)autoSetFloor;
```

- 获取楼层信息
```
- (void)getFloorInfoWithFloorId:(NSString *)floorId callback:(void (^)(XYZFloorInfo *, NSError *))callback;
```

- 结束定位
```
- (void)stopUpdatingLocation;
```

### XYZLocationManagerDelegate

- 更新位置坐标回调
```
- (void)didUpdateLocation:(nonnull XYZLocation *)location;
```

- 切换楼层回调
```
- (void)didEnterFloorId:(nonnull NSString *)floorId;
```

- 定位内部错误回调
```
- (void)didOccurError:(NSError *)error;
```

## 错误码对照表

错误码  | 问题说明
------------- | -------------
20000  | 系统服务异常
20001  | 系统服务连接失败
20100  | 认证未通过
30000  | 未开启定位权限
30100  | 未知异常


