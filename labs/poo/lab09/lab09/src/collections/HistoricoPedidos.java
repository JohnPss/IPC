package collections;

import java.util.ArrayList;
import java.util.List;

import model.Pedido;

public class HistoricoPedidos<T extends Pedido> {
    private List<T> historico;

    public HistoricoPedidos() {
        this.historico = new ArrayList<>();
    }

    public void addPedido(T pedido) {
        historico.add(pedido);
    }

    public List<T> getHistoricoPedidos() {
        return new ArrayList<>(historico);
    }
}
