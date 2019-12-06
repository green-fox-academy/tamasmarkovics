package com.example.demo.models.DTOs;

import com.example.demo.models.entities.LogEntry;

import java.util.List;

public class LogResponseDTO {
    private List<LogEntry> entries;
    private int entry_count;

    public LogResponseDTO(List<LogEntry> entries, int entry_count) {
        this.entries = entries;
        this.entry_count = entry_count;
    }

    public LogResponseDTO() {
    }

    public List<LogEntry> getEntries() {
        return entries;
    }

    public void setEntries(List<LogEntry> entries) {
        this.entries = entries;
    }

    public int getEntry_count() {
        return entry_count;
    }

    public void setEntry_count(int entry_count) {
        this.entry_count = entry_count;
    }
}
