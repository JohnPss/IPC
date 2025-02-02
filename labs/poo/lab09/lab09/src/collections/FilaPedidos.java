package collections;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import exceptions.EmptyOrderException;
import model.Pedido;

public class FilaPedidos<T extends Pedido> {
    private Queue<T> fila;

    public FilaPedidos() {
        this.fila = new LinkedList<>();
    }

    public void addPedido(T pedido) throws EmptyOrderException {
        if (pedido.getProdutos().isEmpty()) {
            throw new EmptyOrderException("Nao pode adicionar pedido vazio");
        }
        fila.add(pedido);
    }

    public T processarProximoPedido() {
        return fila.poll();
    }

    public List<T> getPedidos() {
        return new ArrayList<>(fila);
    }
}