class IMU:
    @staticmethod
    def initialize(self): ...

    @staticmethod
    def getTemperature(self) -> int: ...

    @staticmethod
    def getGyroscope(self) -> list: ...

    @staticmethod
    def getAccelerometer(self) -> list: ...


class Battery:
    @staticmethod
    def isCharging(self) -> int: ...

    @staticmethod
    def getRawData(self) -> int: ...


class Microphone:
    @staticmethod
    def startSampling(self): ...

    @staticmethod
    def stopSampling(self): ...

    @staticmethod
    def getRawData(self) -> int: ...


class Vibrator:
    @staticmethod
    def vibrate(self, ms: int, pulse: int): ...

    @staticmethod
    def stop(self): ...

