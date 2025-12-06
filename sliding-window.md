# Sliding Window

## Types of Sliding window

1. Fixed size sliding window : window size is constant.
2. Variable size sliding window : window expands and shrinks based on a condition.
3. Two pointer window : Left and right pointers move independently but staty ordered.

---

## Template

```python
left = 0
for left in range(0,n):
    include nums[right] into the window
    while window is invalid:
        remove nums[left] from the window
        left++
    update result if needed
```
