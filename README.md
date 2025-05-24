 Giám sát kho IoT - Hệ thống giám sát nhiệt độ, độ ẩm và khí gas

## Mô tả dự án

Dự án **Giám sát kho IoT** sử dụng các cảm biến để theo dõi **nhiệt độ, độ ẩm và nồng độ khí gas** trong kho hàng. Hệ thống giúp cảnh báo sớm khi các thông số vượt ngưỡng an toàn, đảm bảo chất lượng hàng hóa và an toàn kho.

---

## Các thư viện sử dụng

- **NTPClient**: Đồng bộ thời gian thực từ internet để ghi nhận dữ liệu chính xác.
- **Adafruit DHT sensor library**: Đọc dữ liệu từ cảm biến nhiệt độ và độ ẩm DHT11/DHT22.
- **Blynk**: Giao diện điều khiển và giám sát qua điện thoại thông minh.

---

## Hướng dẫn chạy mô phỏng trên Wokwi

1. Truy cập [link mô phỏng Wokwi](https://wokwi.com/projects/431767734886113281).
2. Mở file `diagram.json`.
3. Nhấn nút **Run** để bắt đầu mô phỏng.
4. Quan sát dữ liệu được thu thập từ cảm biến và gửi lên Blynk.

---

## Link GitHub

Bạn có thể xem mã nguồn và tài liệu đầy đủ tại:

[https://github.com/nguyenquoc-coder/Giam_sat_kho_iot/tree/main](https://github.com/nguyenquoc-coder/Giam_sat_kho_iot/tree/main)

---

## Lưu ý

- Trước khi chạy mô phỏng, cần đảm bảo đã thêm đầy đủ các thư viện theo hướng dẫn.
- Kết nối Internet để NTPClient và Blynk hoạt động chính xác.


